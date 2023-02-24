//
// Created by sunxg on 22-3-5.
//

#include "DebugUserAgent.h"
namespace ycpp {

    std::string DebugUserAgent::toMatchTrace(std::list<std::string> highlightNames) {
        std::stringstream o;
        o<<'\n';
        o<<"+=========================================+\n";
        o<<"| Matcher results that have been combined |\n";
        o<<"+=========================================+\n";
        o<<'\n';

        struct my_greater{
            bool operator () (const std::pair<std::shared_ptr<UserAgent>, std::shared_ptr<Matcher>> & o1,
                              const std::pair<std::shared_ptr<UserAgent>, std::shared_ptr<Matcher>> & o2){
                std::shared_ptr<Matcher> m1 = o1.second;
                std::shared_ptr<Matcher> m2 = o2.second;
                return m1->getMatcherSourceLocation()>m2->getMatcherSourceLocation();
            }
        };
        appliedMatcherResults.sort(my_greater());

        for (std::pair<std::shared_ptr<UserAgent>, std::shared_ptr<Matcher>> & pair: appliedMatcherResults){
            o<<'\n';
            o<<"+================\n";
            o<<"+ Applied matcher\n";
            o<<"+----------------\n";
            std::shared_ptr<UserAgent> result = pair.first;
            std::shared_ptr<Matcher> matcher = pair.second;
            o<<matcher->toString();
            o<<"+----------------\n";
            o<<"+ Results\n";
            o<<"+----------------\n";
            for (const std::string & fieldName : result->getAvailableFieldNamesSorted()) {
                AgentField & field = result->get(fieldName);

                if (field.getConfidence() >= 0) {
                    std::string marker = "";
                    if(highlightNames.end() != std::find(highlightNames.begin(),highlightNames.end(),fieldName))
                        marker = " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";

                    o<<"| " << fieldName << '(' << field.getConfidence();
                    if (field.isDefaultValue()) {
                        o<<" => isDefaultValue";
                    }
                    o<<") = " << field.getValue() << marker << '\n';
                }
            }
            o<<"+================\n";
        }
        return o.str();
    }

    bool DebugUserAgent::analyzeMatchersResult() {
        bool passed = true;
        for (const std::string & fieldName : getAvailableFieldNamesSorted()) {
            std::map<long, std::string> receivedValues;
            for (std::pair<std::shared_ptr<UserAgent>, std::shared_ptr<Matcher>> pair: appliedMatcherResults) {
                std::shared_ptr<UserAgent> result = pair.first;
                AgentField & partialField = result->get(fieldName);
                if (partialField.getConfidence() >= 0) {
                    std::string previousValue = receivedValues[partialField.getConfidence()];
                    if (!previousValue.empty()) {
                        if (previousValue != partialField.getValue()) {
                            if (passed) {
                                LOG::error("***********************************************************");
                                LOG::error("***        REALLY IMPORTANT ERRORS IN THE RULESET       ***");
                                LOG::error("*** YOU MUST CHANGE THE CONFIDENCE LEVELS OF YOUR RULES ***");
                                LOG::error("***********************************************************");
                            }
                            passed = false;
                            LOG::error("Found different value for \"%s\" with SAME confidence %s: \"%s\" and \"%s\"",
                                       fieldName, partialField.getConfidence(), previousValue, partialField.getValue());
                        }
                    } else {
                        receivedValues[partialField.getConfidence()] = partialField.getValue();
                    }
                }
            }
        }
        return passed;
    }

    void DebugUserAgent::set(std::shared_ptr<MutableUserAgent> newValuesUserAgent, std::shared_ptr<Matcher> appliedMatcher) {
        auto userAgent = std::shared_ptr<UserAgent>(new ImmutableUserAgent(*newValuesUserAgent.get()));
        auto pair = std::make_pair(userAgent, appliedMatcher);
        appliedMatcherResults.push_back(pair);
        MutableUserAgent::set(newValuesUserAgent, appliedMatcher.get());
    }

    void DebugUserAgent::reset() {
        appliedMatcherResults.clear();
        MutableUserAgent::reset();
    }
}