//
// Created by sunxg on 22-1-30.
//

#include <utils/AntlrUtils.h>
#include "Range.h"
#include <linked_hash.h>
#include <UserAgentParser.h>
#include <tool/tool.h>
#include "Step.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult> Step::walkNextStep(antlr4::tree::ParseTree *tree, const std::string &value) {
        if (nextStep == nullptr) {
            std::string result = value;
            if (value.empty()) {
                result = AntlrUtils::getSourceText((antlr4::ParserRuleContext*)tree);
            }
            if (verbose) {
                LOG::error( "%s Final (implicit) step: %s", logprefix.c_str(), result.c_str());
            }
            return std::make_shared<WalkResult>(tree, result);
        }

        if (verbose) {
            LOG::error( "%s Tree: >>>%s<<<", logprefix.c_str(), AntlrUtils::getSourceText((antlr4::ParserRuleContext *)tree).c_str());
            LOG::error( "%s Enter step(%d): %s", logprefix.c_str(), stepNr, nextStep->toString().c_str());
        }
        std::shared_ptr<WalkResult> result = nextStep->walk(tree, value);
        if (verbose) {
            LOG::error( "%s Result: >>>%s<<<", logprefix.c_str(), result == nullptr ? "null":result->toString().c_str());
            LOG::error( "%s Leave step(%s): %s", logprefix.c_str(), result == nullptr ? "-" : "+", nextStep->toString().c_str());
        }
        return result;
    }

    antlr4::tree::ParseTree *Step::up(antlr4::tree::ParseTree *tree) {
        antlr4::tree::ParseTree * parent = tree->parent;

        // Needed because of the way the ANTLR rules have been defined.
        if (dynamic_cast<UserAgentParser::ProductNameContext *>(parent) != nullptr ||
                dynamic_cast<UserAgentParser::ProductVersionContext *>(parent) != nullptr ||
                dynamic_cast<UserAgentParser::ProductVersionWithCommasContext *>(parent) != nullptr
        ) {
            return up(parent);
        }
        return parent;
    }

    bool Step::treeIsSeparator(antlr4::tree::ParseTree *tree) {
        return dynamic_cast<UserAgentParser::CommentSeparatorContext*>(tree) != nullptr
               || dynamic_cast<antlr4::tree::TerminalNode*>(tree) != nullptr;
    }

    std::string Step::getActualValue(antlr4::tree::ParseTree *tree, const std::string &value) {
        if (value.empty()) {
            return AntlrUtils::getSourceText((antlr4::ParserRuleContext *)tree);
        }
        return value;
    }

    void Step::setNextStep(int newStepNr, std::shared_ptr<Step> newNextStep) {
        this->stepNr = newStepNr;
        this->nextStep = newNextStep;
        std::ostringstream stream;
        for (int i = 0; i < newStepNr + 1; i++) {
            stream << "-->";
        }
        logprefix = stream.str();
    }

    void Step::destroy() {
        nextStep.reset(); //释放nextStep对象
    }

    void Step::setVerbose(bool newVerbose) {
        this->verbose = newVerbose;
    }

    bool Step::canFail() {
        return true; // Default is to assume the step is always needed.
    }

    bool Step::mustHaveInput() {
        return true; // Default is to assume the step always needs input.
    }

    Step::~Step() {
        destroy();
    }
}