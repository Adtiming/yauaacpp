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

#ifndef BEARKNOCKS_YAUAA_CPP_DEF_H
#define BEARKNOCKS_YAUAA_CPP_DEF_H

#ifdef YAUAA_CPP_SHAREDPTR_BOOST
    #include<boost/shared_ptr.hpp>
#else
// must use C++11 or later
    #include<memory>
#endif

#include "antlr4-runtime.h"
#include <list>
#include <map>
#include <string>

typedef std::shared_ptr< std::map<std::string, std::string> >STRMAP_SP;
typedef std::map<std::string, STRMAP_SP> MAPMAPS;
typedef std::shared_ptr<  std::set<std::string> >STRSET_SP;
typedef std::map<std::string, STRSET_SP> MAPSETS;

#endif