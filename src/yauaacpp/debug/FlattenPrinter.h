//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_FLATTENPRINTER_H
#define YAUAACPP_FLATTENPRINTER_H

#include "yauaacpp_def.h"

namespace ycpp {

    class FlattenPrinter: public  Analyzer {

    PrintStream outputStream;

    public FlattenPrinter(PrintStream outputStream) {
    this->outputStream = outputStream;
}


public void inform(const std::string & path, const std::string & value, antlr4::tree::ParseTree * ctx) {
    outputStream.println(path);
}


public void informMeAbout(MatcherAction * matcherAction, const std::string & keyPattern) {
    // Not needed
}

public void lookingForRange(const std::string & treeName, const Range & range) {
// Never called
}

public const linked_hash_set<Range> getRequiredInformRanges(const std::string & treeName){
    // Never called
    return Collections.emptySet();
}

public void informMeAboutPrefix(MatcherAction * matcherAction, const std::string & treeName, const std::string & prefix) {
    // Never called
}

public linked_hash_set<size_t> getRequiredPrefixLengths(const std::string & treeName){
    // Never called
    return Collections.emptySet();
}


public std::map<std::string,std::map<std::string, std::string>> getLookups() {
    // Never called
    return Collections.emptyMap();
}


public std::map<std::string, std::set<std::string>> getLookupSets() {
    // Never called
    return Collections.emptyMap();
}


public std::list<TestCase> getTestCases() {
    // Never called
    return Collections.emptyList();
}

};

}
#endif //YAUAACPP_FLATTENPRINTER_H
