//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHER_H
#define YAUAACPP_MATCHER_H

#include <config/MatcherConfig.h>
#include "../yauaacpp_def.h"
#include "src/yauaacpp/UserAgent.h"
#include "Analyzer.h"
#include "MatchesList.h"
#include "MatcherAction.h"

namespace ycpp {
    class MatcherVariableAction;

    class Matcher {
    private:
        Analyzer * analyzer;
        std::list<MatcherAction * > allActions; // for free Action Objects
        std::list<MatcherAction * > dynamicActions;
        std::list<MatcherAction * > fixedStringActions;
        std::shared_ptr<MutableUserAgent> newValuesUserAgent;
        long actionsThatRequireInput;
        bool verbose;
        bool permanentVerbose;
        std::string sourceFileName;
        int sourceFileLineNumber;



        long countActionsThatMustHaveMatches(const std::list<MatcherAction * > & actions);

        std::set <std::string> getAllPossibleFieldNames(const std::list< MatcherAction *> & actions);

        std::map<std::string, std::set < MatcherAction *>>
                informMatcherActionsAboutVariables ;
        bool alreadyNotifiedAnalyzerWeReceivedInput = false;
        long actionsThatRequireInputAndReceivedInput = 0;

    public:

        Matcher();
        Matcher(Analyzer * analyzer);
        ~Matcher();

        std::list<MatcherVariableAction* > variableActions;

        void initMatcher(Analyzer * analyzer, const std::set<std::string> & wantedFieldNames,
                         std::shared_ptr<MatcherConfig> matcherConfig);

        std::string getMatcherSourceLocation() const {
            return matcherSourceLocation;
        }

        std::string getSourceFileName() const {
            return sourceFileName;
        }

        int getSourceFileLineNumber() const {
            return sourceFileLineNumber;
        }

        std::string matcherSourceLocation;

        void destroy();

        std::shared_ptr<MAPMAPS> getLookups();

        std::shared_ptr<MAPSETS> getLookupSets();

        void initialize();


        std::set <std::string> getAllPossibleFieldNames();


        void lookingForRange(const std::string & treeName, const Range & range);

        void informMeAbout(MatcherAction * matcherAction, const std::string & keyPattern);

        void informMeAboutPrefix(MatcherAction * matcherAction, const std::string & keyPattern, const std::string & prefix);

        void informMeAboutVariable(MatcherAction * matcherAction, const std::string & variableName);

        /**
         * Fires all matcher actions.
         * IFF all success then we tell the userAgent
         *
         * @param userAgent The useragent that needs to analyzed
         */
         void analyze(std::shared_ptr<MutableUserAgent> userAgent);

        bool getVerbose() {
            return verbose;
        }

        void receivedInput();

        long getActionsThatRequireInput() {
            return actionsThatRequireInput;
        }


        long getActionsThatRequireInputAndReceivedInput() {
            return actionsThatRequireInputAndReceivedInput;
        }


        void gotMyFirstStartingPoint() {
            actionsThatRequireInputAndReceivedInput++;
        }


        void failImmediately() {
            actionsThatRequireInputAndReceivedInput = LONG_MIN; // So it will never match the expected
        }


        void setVerboseTemporarily(bool newVerbose);


        void reset();

        std::list<Match> getMatches();

        std::list<Match> getUsedMatches();


        std::string toString();

    };


    std::ostringstream & operator<<(std::ostringstream &o, Matcher &m);
    std::ostringstream & operator<<(std::ostringstream &o, Matcher *&m);
    std::ostringstream & operator<<(std::ostringstream &o, std::vector<Matcher *> &v);
    std::ostringstream & operator<<(std::ostringstream &o, const std::vector<Matcher *> &v);
}

#endif //YAUAACPP_MATCHER_H
