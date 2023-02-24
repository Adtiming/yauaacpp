//
// Created by sunxg on 22-1-30.
//
#include "Matcher.h"
#include <list>
#include "MatcherExtractAction.h"
#include "MatcherRequireAction.h"
#include "MatcherFailIfFoundAction.h"
#include "UselessMatcherException.h"
#include "MatcherVariableAction.h"
#include "tool/dir.h"
#include "ImmutableUserAgent.h"

namespace ycpp {


    long Matcher::countActionsThatMustHaveMatches(const std::list<MatcherAction *> & actions) {
        long actionsThatMustHaveMatches = 0;
        for (MatcherAction * action : actions) {
            // If an action exists which without any data can be valid, then we must force the evaluation
            action->reset();
            if (action->mustHaveMatches()) {
                actionsThatMustHaveMatches++;
            }
        }
        return actionsThatMustHaveMatches;
    }

    std::set<std::string> Matcher::getAllPossibleFieldNames(const std::list<MatcherAction * > & actions) {
        std::set <std::string> results;
        for (MatcherAction * action: actions) {
            if (nullptr != dynamic_cast<MatcherExtractAction*>(action)) {
                MatcherExtractAction * extractAction = dynamic_cast<MatcherExtractAction*>(action);
                results.insert(extractAction->getAttribute());
            }
        }
        return results;
    }


    void Matcher::destroy() {
        for(MatcherAction * ma : allActions)
            delete ma;
        allActions.clear();

        dynamicActions.clear();
        fixedStringActions.clear();
        variableActions.clear();

    }

    std::shared_ptr<MAPMAPS> Matcher::getLookups() {
        return analyzer->getLookups();
    }

    std::shared_ptr<MAPSETS> Matcher::getLookupSets() {
        return analyzer->getLookupSets();
    }

    void Matcher::initialize() {
        long newEntries = 0;
        long initStart = get_cur_msec();
        try {
            for (MatcherVariableAction * variableAction : variableActions) {
                newEntries += variableAction->initialize(variableAction);
            }
        } catch (InvalidParserConfigurationException & e) {
            throw InvalidParserConfigurationException("Syntax error.(" + matcherSourceLocation + ")", e);
        }

        std::set <MatcherAction * > uselessRequireActions;
        for (MatcherAction * dynamicAction : dynamicActions) {
            try {
                newEntries += dynamicAction->initialize(dynamicAction);
            } catch (InvalidParserConfigurationException & e) {
                if (!starts_with(std::string(e.what()),std::string("It is useless to put a fixed value"))) {// Ignore fixed values in require
                    throw InvalidParserConfigurationException(
                            "Syntax error.(" + matcherSourceLocation + ")" + e.what(), e);
                }
                uselessRequireActions.insert(dynamicAction);
            }
        }

        for (MatcherAction * action: dynamicActions) {
            if (nullptr != dynamic_cast<MatcherExtractAction*>(action)) {
                if (((MatcherExtractAction*) action)->isFixedValue()) {
                    fixedStringActions.push_back(action);
                    action->obtainResult();
                }
            }
        }

        for(auto & action:fixedStringActions) {
            dynamicActions.remove(action);
        }
        for(auto & action:uselessRequireActions) {
            dynamicActions.remove(action);
            allActions.remove(action);
            delete action;
        }

        // Verify that a variable only contains the variables that have been defined BEFORE it (also not referencing itself).
        // If all is ok we link them
        std::set <MatcherAction * > seenVariables;
        for (auto & variableAction: variableActions) {
            seenVariables.insert(variableAction); // Add myself
            auto it = informMatcherActionsAboutVariables.find(variableAction->getVariableName());
            if (it != informMatcherActionsAboutVariables.end()  && !it->second.empty()) {
                std::set < MatcherAction *> & the_set = it->second;
                variableAction->setInterestedActions(the_set);
                for (auto & interestedAction : the_set) {
                    if (seenVariables.find(interestedAction) != seenVariables.end()) {
                        throw InvalidParserConfigurationException(
                                "Syntax error (" + matcherSourceLocation + "): The line >>" + interestedAction->toString() + "<< " +
                                "is referencing variable @" + variableAction->getVariableName() +
                                " which is not defined yet.");
                    }
                }
            }
        }

        // Check if any variable was requested that was not defined.
        std::set <std::string> missingVariableNames;
        std::set <std::string> seenVariableNames;
        for(auto m:seenVariables) seenVariableNames.insert(((MatcherVariableAction*)m)->getVariableName());

        for(auto pair:informMatcherActionsAboutVariables){
            const std::string & variableName = pair.first;
            if (seenVariableNames.end() == seenVariableNames.find(variableName)) {
                missingVariableNames.insert(variableName);
            }
        }

        if (!missingVariableNames.empty()) {
            throw InvalidParserConfigurationException(
                    "Syntax error (" + matcherSourceLocation + "): Used, yet undefined variables: " +
                    to_string(missingVariableNames.begin(),missingVariableNames.end()));
        }

        // Make sure the variable actions are BEFORE the rest in the list
        dynamicActions.insert(dynamicActions.begin(),variableActions.begin(),variableActions.end());

        actionsThatRequireInput = countActionsThatMustHaveMatches(dynamicActions);

        long initFinish = get_cur_msec();
        if (newEntries > 3000) {
            LOG::warn("Large matcher: %ld in %ld ms:.(%s)", newEntries, (initFinish - initStart),
                     matcherSourceLocation.c_str());
        }

        if (verbose) {
            LOG::error( "---------------------------");
        }

    }

    std::set<std::string> Matcher::getAllPossibleFieldNames() {
        std::set <std::string> results;
        auto t = getAllPossibleFieldNames(dynamicActions);
        results.insert(t.begin(),t.end());
        auto t1 = getAllPossibleFieldNames(fixedStringActions);
        results.insert(t1.begin(),t1.end());
        results.erase(SET_ALL_FIELDS);
        return results;
    }

    void Matcher::lookingForRange(const std::string & treeName, const Range & range) {
        analyzer->lookingForRange(treeName, range);
    }

    void Matcher::informMeAbout(MatcherAction * matcherAction, const std::string &keyPattern) {
        analyzer->informMeAbout(matcherAction, keyPattern);
    }

    void Matcher::informMeAboutPrefix(MatcherAction * matcherAction, const std::string &keyPattern, const std::string &prefix) {
        analyzer->informMeAboutPrefix(matcherAction, keyPattern, prefix);
    }

    void Matcher::informMeAboutVariable(MatcherAction * matcherAction, const std::string &variableName) {
        auto it = informMatcherActionsAboutVariables.find(variableName);
        if(it == informMatcherActionsAboutVariables.end()){
            informMatcherActionsAboutVariables[variableName];
            it = informMatcherActionsAboutVariables.find(variableName);
        }
        std::set < MatcherAction *> & analyzerSet = it->second;
        analyzerSet.insert(matcherAction);
    }

    void Matcher::analyze(std::shared_ptr<MutableUserAgent> userAgent) {
        if (verbose) {
            LOG::error( "");
            LOG::error( "--- Matcher.(%s) ------------------------", matcherSourceLocation.c_str());
            LOG::error( "ANALYSE ----------------------------");
            bool good = true;
            for (MatcherAction * action : dynamicActions) {
                if (action->cannotBeValid()) {
                    LOG::error("CANNOT BE VALID : %s", action->getMatchExpression().c_str());
                    good = false;
                }
            }
            for (MatcherAction * action : dynamicActions) {
                if (!action->obtainResult()) {
                    LOG::error("FAILED : %s", action->getMatchExpression().c_str());
                    good = false;
                }
            }
            if (good) {
                LOG::error( "COMPLETE ----------------------------");
            } else {
                LOG::error( "INCOMPLETE ----------------------------");
                return;
            }
        } else {
            if (actionsThatRequireInput != actionsThatRequireInputAndReceivedInput) {
                return;
            }
            for (MatcherAction * action : dynamicActions) {
                if (action->obtainResult()) {
                    continue;
                }
                return; // If one of them is bad we skip the rest
            }
        }
        userAgent->set(newValuesUserAgent,this);
    }

    void Matcher::receivedInput() {
        if (alreadyNotifiedAnalyzerWeReceivedInput) {
            return;
        }
        analyzer->receivedInput(this);
        alreadyNotifiedAnalyzerWeReceivedInput = true;
    }

    void Matcher::reset() {
        // If there are no dynamic actions we have fixed strings only
        alreadyNotifiedAnalyzerWeReceivedInput = false;
        actionsThatRequireInputAndReceivedInput = 0;
        verbose = permanentVerbose;
        for (MatcherAction * action : dynamicActions) {
            action->reset();
        }
    }

    std::list<Match> Matcher::getMatches() {
        std::list<Match> allMatches;
        for (MatcherAction * action : dynamicActions) {
            MatchesList * t = action->getMatches();
            allMatches.insert(allMatches.end(),t->begin(),t->end());
        }
        return allMatches;
    }

    void Matcher::setVerboseTemporarily(bool newVerbose) {
        for (MatcherAction * action : dynamicActions) {
            action->setVerbose(newVerbose, true);
        }
    }

    std::list<Match> Matcher::getUsedMatches() {
        std::list<  Match > allMatches;
        for (MatcherAction * action : dynamicActions) {
            if (action->cannotBeValid()) {
                return std::list<Match>(); // There is NO way one of them is valid
            }
        }
        for (MatcherAction * action : dynamicActions) {
            if (!action->obtainResult()) {
                return std::list<Match>(); // There is NO way one of them is valid
            } else {
                MatchesList * t = action->getMatches();
                allMatches.insert(allMatches.begin(),t->begin(),t->end());
            }
        }
        return allMatches;
    }

    std::string Matcher::toString() {
        std::stringstream o;
        o << "MATCHER.(" << matcherSourceLocation.c_str() << "):\n" << "    VARIABLE:\n";
        for (MatcherAction * action : dynamicActions) {
            if (nullptr != dynamic_cast<MatcherVariableAction*>(action)) {
                o << "        @" << ((MatcherVariableAction*) action)->getVariableName()
                  << ":    " << action->getMatchExpression().c_str() << '\n';
                std::list<std::string> l = action->getMatches()->toStrings();
                o << "        -->" << to_string(l.begin(),l.end()) << '\n';
            }
        }
        o << "    REQUIRE:\n";
        for (MatcherAction * action : dynamicActions) {
            if (nullptr != dynamic_cast<MatcherRequireAction*>(action)) {
                o << "        " << action->getMatchExpression().c_str() << '\n';
                if (action->getMatches() != nullptr) {
                    std::list<std::string> l = action->getMatches()->toStrings();
                    o << "        -->" << to_string(l.begin(),l.end()) << '\n';
                }
            }
        }
        o << "    FAIL_IF_FOUND:\n";
        for (MatcherAction * action : dynamicActions) {
            if (nullptr != dynamic_cast<MatcherFailIfFoundAction*>(action)) {
                o << "        " << action->getMatchExpression().c_str() << '\n';
                if (action->getMatches() != nullptr) {
                    std::list<std::string> l = action->getMatches()->toStrings();
                    o << "        -->" << to_string(l.begin(),l.end()) << '\n';
                }
            }
        }
        o << "    EXTRACT:\n";
        for (MatcherAction * action : dynamicActions) {
            if (nullptr != dynamic_cast<MatcherExtractAction*>(action)) {
                o << "        " << action->toString().c_str() << '\n';
                if (action->getMatches() != nullptr) {
                    std::list<std::string> l = action->getMatches()->toStrings();
                    o << "        -->" << to_string(l.begin(),l.end()) << '\n';
                }
            }
        }
        for (MatcherAction * action : fixedStringActions) {
            o << "        " << action << '\n';
        }
        return o.str();
    }

    int g_matcher_cnt = 0;
    Matcher::~Matcher() {
        destroy();
        g_matcher_cnt --;
        //printf("g_matcher_cnt = %d\n",g_matcher_cnt);
    }

    Matcher::Matcher() {
        g_matcher_cnt ++;
        permanentVerbose = false;
        verbose = false;
        this->analyzer = nullptr;
        actionsThatRequireInput = 0;
    }

    Matcher::Matcher(Analyzer * analyzer) {
        g_matcher_cnt ++;
        permanentVerbose = false;
        verbose = false;
        this->analyzer = analyzer;
        actionsThatRequireInput = 0;
    }


    void Matcher::initMatcher(Analyzer *analyzer, const std::set<std::string> &wantedFieldNames, std::shared_ptr<MatcherConfig> matcherConfig) {
        this->analyzer = analyzer;
        actionsThatRequireInput = 0;

        this->newValuesUserAgent = std::make_shared<MutableUserAgent>(wantedFieldNames);

        sourceFileName = matcherConfig->getMatcherSourceFilename();
        sourceFileLineNumber = matcherConfig->getMatcherSourceLineNumber();
        matcherSourceLocation = sourceFileName + ':' + itos(sourceFileLineNumber);

        permanentVerbose = false;
        verbose = false;
        std::list<std::string> options = matcherConfig->getOptions();
        if (!options.empty() && std::find(options.begin(),options.end(),"verbose") != options.end()) {
            verbose = true;
        }

        bool hasActiveExtractConfigs = false;
        bool hasDefinedExtractConfigs = false;

        if (verbose) {
            LOG::error( "---------------------------");
            LOG::error( "- MATCHER -");
        }

        for (ConfigLine configLine : matcherConfig->getConfigLines()) {
            if (verbose) {
                LOG::error( "%s: %s", configLine.getTypeStr().c_str(), configLine.getExpression().c_str());
            }
            switch (configLine.getType()) {
                case ConfigLine::VARIABLE:
                    variableActions.push_back(
                            new MatcherVariableAction(configLine.getAttribute(), configLine.getExpression(),this));
                    allActions.push_back(variableActions.back());
                    break;
                case ConfigLine::REQUIRE:
                    dynamicActions.push_back(
                            new MatcherRequireAction(configLine.getExpression(),this));
                    allActions.push_back(dynamicActions.back());
                    break;
                case ConfigLine::FAIL_IF_FOUND:
                    dynamicActions.push_back(
                            new MatcherFailIfFoundAction(configLine.getExpression(), this));
                    allActions.push_back(dynamicActions.back());
                    break;
                case ConfigLine::EXTRACT:
                    hasDefinedExtractConfigs = true;
                    // If we have a restriction on the wanted fields we check if this one is needed at all
                    if (wantedFieldNames.empty() || wantedFieldNames.end()!=std::find(wantedFieldNames.begin(),wantedFieldNames.end(),configLine.getAttribute())) {
                        MatcherExtractAction * action =
                                new MatcherExtractAction(configLine.getAttribute(), configLine.getConfidence(),
                                                         configLine.getExpression(), this);
                        dynamicActions.push_back(action);
                        allActions.push_back(action);

                        // Make sure the field actually exists
                        newValuesUserAgent->set(configLine.getAttribute(), "Dummy", -9999);
                        action->setResultAgentField((MutableAgentField*)&newValuesUserAgent->get(configLine.getAttribute()));

                        hasActiveExtractConfigs = true;
                    } else {
                        dynamicActions.push_back(
                                new MatcherRequireAction(configLine.getExpression(), this));
                        allActions.push_back(dynamicActions.back());
                    }
                    break;
                default:
                    break;
            }
        }

        if (!hasDefinedExtractConfigs) {
            throw InvalidParserConfigurationException("Matcher does not extract anything:" + matcherSourceLocation);
        }

        if (!hasActiveExtractConfigs) {
            throw UselessMatcherException("Does not extract any wanted fields" + matcherSourceLocation);
        }

    }

}
