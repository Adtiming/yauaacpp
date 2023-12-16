/*
 * Yet Another UserAgent Analyzer cpp version
 * Copyright (C) 2023 Adtiming
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



#ifndef YAUAACPP_ABSTRACTUSERAGENTANALYZERDIRECT_H
#define YAUAACPP_ABSTRACTUSERAGENTANALYZERDIRECT_H

#include <mutex>
#include <vector>
#include <map>
#include "yauaacpp_def.h"
#include "AnalyzerPreHeater.h"

/*
#include "analyze/Analyzer.h"
#include <analyze/MatcherList.h>
#include <parse/UserAgentTreeFlattener.h>
#include <analyze/Matcher.h>
#include <config/AnalyzerConfig.h>
#include <calculate/FieldCalculator.h>
#include <utils/CheckLoggingDependencies.h>
#include <calculate/ConcatNONDuplicatedCalculator.h>
#include <calculate/MajorVersionCalculator.h>
#include <calculate/CalculateAgentClass.h>
#include <calculate/CalculateAgentName.h>
#include <calculate/CalculateNetworkType.h>
#include <calculate/CalculateDeviceName.h>
#include <calculate/CalculateDeviceBrand.h>
#include <calculate/CalculateAgentEmail.h>
#include <config/ConfigLoader.h>
*/

namespace ycpp {
    class AnalyzerConfig;
    class ImmutableUserAgent;
    class GetAllPathsAnalyzer;
    class MatcherAction;
    class UserAgentTreeFlattener;
    class MatcherList;
    class DirExt;
    class FieldCalculator;
    class MutableUserAgent;
    class UserAgent;

    class AbstractUserAgentAnalyzerDirect :public AnalyzerPreHeater, virtual public Analyzer {

    private:
        // We set this to 1000000 always.
        // Why?
        // At the time of writing this the actual HashMap size needed about 410K entries.
        // To keep the bins small the load factor of 0.75 already puts us at the capacity of 1048576
        static const int INFORM_ACTIONS_HASHMAP_CAPACITY = 1000000;

        std::vector<Matcher *> allMatchers;
        std::vector<Matcher *> zeroInputMatchers;
        std::map<std::string, linked_hash_set<MatcherAction *>> informMatcherActions;

        bool showMatcherStats = false;

        std::list<std::shared_ptr<TestCase> > testCases ;

        std::shared_ptr<MAPMAPS> lookups;
        std::shared_ptr<MAPSETS> lookupSets;

        std::shared_ptr<AnalyzerConfig> config;


        void showDeserializationStats();

        bool _delayInitialization = true;


        void invalidateCaches();

        void verifyWeAreNotAskingForImpossibleFields();

        bool matchersHaveBeenInitialized = false;

        std::set<std::string> allPossibleFieldNamesCache;


        std::list<std::string> allPossibleFieldNamesSortedCache;


// These are the actual subrange we need for the paths.
        std::map<std::string, linked_hash_set<Range>> informMatcherActionRanges;

        // These are the paths for which we have prefix requests.
        std::map<std::string, linked_hash_set<size_t >> informMatcherActionPrefixesLengths;


        MatcherList * touchedMatchers;

    public:
        AbstractUserAgentAnalyzerDirect();
        ~AbstractUserAgentAnalyzerDirect();

        static const int DEFAULT_USER_AGENT_MAX_LENGTH = 2048;
        int userAgentMaxLength;
        bool loadTests;



        std::vector<Matcher *> getAllMatchers() {
            return allMatchers;
        }

        MatcherList * getTouchedMatchers();

        // If we want ALL fields this is null. If we only want specific fields this is a list of names.
        std::set<std::string> wantedFieldNames; // NOSONAR: Only accessed via Builder.



        std::list<std::shared_ptr<TestCase> > getTestCases() override {
            return testCases;
        }


        std::shared_ptr<MAPMAPS> getLookups() {
            return lookups;
        }


        std::shared_ptr<MAPSETS> getLookupSets() {
            return lookupSets;
        }

        UserAgentTreeFlattener * flattener;



        void addAnalyzerConfig(const AnalyzerConfig & analyzerConfig);

        /*
         * Initialize the default values
         */
        void initTransientFields() {
//            touchedMatchers = new MatcherList();
        }


        /**
         * This is used to configure the provided Kryo instance if Kryo serialization is desired.
         * The expected type here is Object because otherwise the Kryo library becomes
         * a mandatory dependency on any project that uses Yauaa.
         * @param kryo The instance of com.esotericsoftware.kryo.Kryo that needs to be configured.
         */
//        static void configureKryo(Object kryo) {
//            //KryoConfig.configureKryo((Kryo) kryo);
//        }

        std::set<std::string> getAllPossibleFieldNames();


        void delayInitialization() {
            _delayInitialization = true;
        }

        void immediateInitialization() {
            _delayInitialization = false;
        }

        void setShowMatcherStats(bool newShowMatcherStats) {
            this->showMatcherStats = newShowMatcherStats;
        }

        bool getShowMatcherStats() {
            return showMatcherStats;
        }

        void dropTests() {
            loadTests = false;
            testCases.clear();
        }

        void keepTests() {
            loadTests = true;
        }

        bool willKeepTests() {
            return loadTests;
        }

        long getNumberOfTestCases() {
            return testCases.size();
        }
        std::list<std::string> getAllPossibleFieldNamesSorted();

        // --------------------------------------------

        virtual /**
         * In some cases it was found that simply dereferencing the instance and letting the GC clean it all up was "too hard".
         * To assist in these kinds of problem cases this method will wipe the internal data structures as much as possible.
         * After calling this method this instance becomes unusable and cannot be 'repaired'.
         * Normal applications will never need this-> Simply dereferencing the analyzer will clean everything,
         * no memory leaks (that we know of).
         */
        void destroy();

        // --------------------------------------------

        void loadResources(const DirExt * resourceString) {
            loadResources(resourceString, showMatcherStats, false);
        }

        void loadResources(const DirExt * resourceString, bool showLoadMessages, bool optionalResources);

        void finalizeLoadingRules();

        void initializeMatchers();

        void lookingForRange(const std::string & treeName, const Range & range);

        // We do not want to put ALL lengths in the hashmap for performance reasons
        enum {MAX_PREFIX_HASH_MATCH = 3};

        // Calculate the max length we will put in the hashmap.
        static size_t firstCharactersForPrefixHashLength(const std::string & input, size_t maxChars);

        static std::string firstCharactersForPrefixHash(const std::string & input, size_t maxChars);


        void informMeAboutPrefix(MatcherAction * matcherAction, const std::string & treeName, const std::string & prefix) override ;


        linked_hash_set<size_t> * getRequiredPrefixLengths(const std::string & treeName) override ;

        void informMeAbout(MatcherAction * matcherAction, const std::string & keyPattern) override ;

        bool verbose = false;

        void setVerbose(bool newVerbose);

        void setUserAgentMaxLength(int newUserAgentMaxLength) {
            if (newUserAgentMaxLength <= 0) {
                userAgentMaxLength = DEFAULT_USER_AGENT_MAX_LENGTH;
            } else {
                userAgentMaxLength = newUserAgentMaxLength;
            }
        }

        int getUserAgentMaxLength() {
            return this->userAgentMaxLength;
        }

        void setAsHacker(std::shared_ptr<MutableUserAgent> userAgent, int confidence);



        void receivedInput(Matcher * matcher) override ;

        /**
         * Resets the state of the Analyzer to the default state.
         */
        void reset();

        /**
         * Parses and analyzes the provided useragent string
         * @param userAgentString The User-Agent std::string that is to be parsed and analyzed
         * @return An ImmutableUserAgent record that holds all of the results.
         */

        std::shared_ptr<UserAgent> parse(const std::string & userAgentString) override;

        /**
         * Parses and analyzes the useragent string provided in the MutableUserAgent instance.
         * NOTE: This method is internally synchronized because the way the analyzer works is not reentrant.
         * @param userAgent The MutableUserAgent instance that is to be parsed and that gets all results
         * @return An ImmutableUserAgent copy of the results that is suitable for further usage and caching.
         */
        virtual std::shared_ptr<UserAgent> parsePtr(std::shared_ptr<MutableUserAgent> userAgent);

        static std::list<std::string> HARD_CODED_GENERATED_FIELDS ;

        static std::list<std::string> init();

        bool isWantedField(const std::string & fieldName);

        std::set<std::string> getWantedFieldNames(){
            return wantedFieldNames;
        }

        std::list<std::shared_ptr<FieldCalculator> > fieldCalculators ;

        void setFieldCalculators(std::list<std::shared_ptr<FieldCalculator> > & newFieldCalculators);

        std::shared_ptr<MutableUserAgent> hardCodedPostProcessing(std::shared_ptr<MutableUserAgent> userAgent);

        const linked_hash_set<Range> & getRequiredInformRanges(const std::string & treeName) override;

        void inform(const std::string & key, const std::string & value, antlr4::tree::ParseTree * ctx);

        void inform(const std::string & match, const std::string & key, const std::string & value, antlr4::tree::ParseTree * ctx);


        static std::list<std::string> getAllPaths(const std::string & agent);

        static std::shared_ptr<GetAllPathsAnalyzer> getAllPathsAnalyzer(const std::string & agent);


        virtual std::string toString();
    };


// ===============================================================================================================

    class GetAllPathsAnalyzer: public  Analyzer {
    private:
        std::list<std::string> values;

        UserAgent * result;
        UserAgentTreeFlattener * flattener;

        GetAllPathsAnalyzer(){}
    public:
        explicit GetAllPathsAnalyzer(const std::string & useragent);
        ~GetAllPathsAnalyzer();

        std::list<std::string> getValues() {
            return values;
        }

        UserAgent * getResult() {
            return result;
        }

        void inform(const std::string & path, const std::string & value, antlr4::tree::ParseTree * ctx) {
            values.emplace_back(path);
            values.emplace_back(path + "=\"" + value + "\"");
            std::ostringstream o;
            o << path.c_str() <<"{\"" << AbstractUserAgentAnalyzerDirect::firstCharactersForPrefixHash(value, AbstractUserAgentAnalyzerDirect::MAX_PREFIX_HASH_MATCH) << "\"";
            values.emplace_back(o.str());
        }

        void informMeAbout(MatcherAction * matcherAction, const std::string & keyPattern) {
            // Not needed to only get all paths
        }

        void lookingForRange(const std::string & treeName, const Range & range) {
    // Not needed to only get all paths
        }

        const linked_hash_set<Range> & getRequiredInformRanges(const std::string & treeName) {
    // Not needed to only get all paths
            static linked_hash_set<Range> set;
            return set;
        }


        void informMeAboutPrefix(MatcherAction * matcherAction, const std::string & treeName, const std::string & prefix) {
            // Not needed to only get all paths
        }


        linked_hash_set<size_t> * getRequiredPrefixLengths(const std::string & treeName) {
    // Not needed to only get all paths
            static linked_hash_set<size_t> t;
            return &t;
        }


        std::shared_ptr<MAPMAPS> getLookups() {
            // Not needed to only get all paths
            return std::make_shared<MAPMAPS>();
        }


        std::shared_ptr<MAPSETS> getLookupSets() {
            // Not needed to only get all paths
            return std::make_shared<MAPSETS>();
        }


        std::list<std::shared_ptr<TestCase> > getTestCases() {
            std::list<std::shared_ptr<TestCase> > t;
            return t;
        }
    };


// ===============================================================================================================

    class AbstractUserAgentAnalyzerDirectBuilder {
    public:
        typedef AbstractUserAgentAnalyzerDirectBuilder B;
    protected:
        std::shared_ptr<AbstractUserAgentAnalyzerDirect> uaa;
        bool didBuildStep = false;
        int preheatIterations = 0;

        std::list<DirExt>               *resources         ;
        std::list<DirExt>               *optionalResources ;
        std::list<std::string>          yamlRules         ;
        std::list<std::shared_ptr<FieldCalculator> > fieldCalculators  ;
        void registerFieldCalculator(std::shared_ptr<FieldCalculator> fieldCalculator);


    public:
        std::set<std::string> allFieldsForWhichACalculatorExists;

        AbstractUserAgentAnalyzerDirectBuilder(std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa);
        virtual ~AbstractUserAgentAnalyzerDirectBuilder();

        void failIfAlreadyBuilt();

        /**
         * Drop the default set of rules. Useful in parsing ONLY company specific useragents.
         * @return the current Builder instance.
         */
        B & dropDefaultResources();

        /**
         * Add a set of additional rules. Useful in handling specific cases.
         * @param resourceString The resource list that needs to be added.
         * @return the current Builder instance.
         */
        B & addResources(const std::string &path, const std::string & ext);

        /**
         * Add a set of additional rules. Useful in handling specific cases.
         * The startup will continue even if these do not exist.
         * @param resourceString The resource list that should to be added.
         * @return the current Builder instance.
         */
        B & addOptionalResources(const std::string &path, const std::string & ext);

        /**
         * Add a set of additional rules. Useful in handling specific cases.
         * The startup will continue even if these do not exist.
         * @param yamlRule The Yaml expression that should to be added.
         * @return the current Builder instance.
         */
        B & addYamlRule(const std::string & yamlRule);

        /**
         * Use the available testcases to preheat the jvm on this analyzer.
         * @param iterations How many testcases must be run
         * @return the current Builder instance.
         */
        B & preheat(int iterations);

        /**
         * Use the available testcases to preheat the jvm on this analyzer.
         * All available testcases will be run exactly once.
         * @return the current Builder instance.
         */
        B & preheat();

        /**
         * Specify an additional field that we want to retrieve.
         * @param fieldName The name of the additional field
         * @return the current Builder instance.
         */
        B & withField(const std::string & fieldName);

        /**
         * Specify a set of additional fields that we want to retrieve.
         * @param fieldNames The collection of names of the additional fields
         * @return the current Builder instance.
         */
        template <typename Iter> B withFields(Iter first, Iter end) {
            for (;first != end; first++) {
                withField(*first);
            }
            return *this;
        }
//
//        /**
//         * Specify a set of additional fields that we want to retrieve.
//         * @param fieldNames The array of names of the additional fields
//         * @return the current Builder instance.
//         */
//        B & withFields(const std::string &... fieldNames) {
//            for (const std::string & fieldName : fieldNames) {
//                withField(fieldName);
//            }
//            return *this;
//        }

        /**
         * Specify that we simply want to retrieve all possible fields.
         * @return the current Builder instance.
         */
        B & withAllFields();

        /**
         * Log additional information during the startup of the analyzer.
         * @return the current Builder instance.
         */
        B & showMatcherLoadStats();

        /**
         * Set the stats logging during the startup of the analyzer back to the default of "minimal".
         * @return the current Builder instance.
         */
        B & hideMatcherLoadStats();

        /**
         * Set maximum length of a useragent for it to be classified as Hacker without any analysis.
         * @param newUserAgentMaxLength The new maximum length of a useragent for it to be classified as Hacker without any analysis.
         * @return the current Builder instance.
         */
        B & withUserAgentMaxLength(int newUserAgentMaxLength);

        /**
         * Retain all testcases in memory after initialization.
         * @return the current Builder instance.
         */
        B & keepTests();

        /**
         * Remove all testcases in memory after initialization.
         * @return the current Builder instance.
         */
        B & dropTests();

        /**
         * Load all patterns and rules but do not yet build the lookup hashMaps yet.
         * For the engine to run these lookup hashMaps are needed so they will be constructed once "just in time".
         * @return the current Builder instance.
         */
        B & delayInitialization();

        /**
         * Load all patterns and rules and immediately build the lookup hashMaps.
         * @return the current Builder instance.
         */
        B & immediateInitialization();


        void verifyCalculatorDependencyOrdering();


        /**
         * Specify a new cache size (0 = disable caching).
         * @param newCacheSize The new cache size value
         * @return the current Builder instance.
         */
        virtual B & withCache(int newCacheSize){return *this;};

        /**
         * Disable caching.
         * @return the current Builder instance.
         */
        virtual B & withoutCache(){return *this;};

        /**
         * Construct the analyzer and run the preheat (if requested).
         * @return the new analyzer instance.
         */
        std::shared_ptr<AbstractUserAgentAnalyzerDirect> build();
    };

}
#endif //YAUAACPP_ABSTRACTUSERAGENTANALYZERDIRECT_H
