//
// Created by sunxg on 22-2-16.
//

#ifndef YAUAACPP_PACKAGEDRULES_H
#define YAUAACPP_PACKAGEDRULES_H

#include "yauaacpp_def.h"
#include <string>
#include <list>
#include <tool/dir.h>

namespace ycpp {

    class PackagedRules {
    private:
        static std::list<std::shared_ptr<Resource>> RULE_FILES_LIST;
    public:
        static const std::list<std::shared_ptr<Resource>> & getRuleFileNames();
    };

}

#endif //YAUAACPP_PACKAGEDRULES_H
