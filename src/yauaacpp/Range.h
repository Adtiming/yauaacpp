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

#ifndef YAUAACPP_RANGE_H
#define YAUAACPP_RANGE_H

#include <string>

namespace ycpp {
    class Range {

    private:
        int first;
        int last;

    public:
        Range() {
            first = -1;
            last = -1;
        }
        Range(int first, int last) {
            this->first = first;
            this->last = last;
        }

        int getFirst() const {
            return first;
        }

        int getLast() const {
            return last;
        }


        std::string toString() const;

        bool operator<(const Range &other) const {
            if(first < other.first)
                return true;
            return last < other.first;
        }
    };

} // namespace ycpp



namespace std {
    // 散列, hash值计算
    template<>
    struct hash<ycpp::Range> {
        using result_type = size_t;
        using argument_type = ycpp::Range;

        size_t operator()(const ycpp::Range &rhs) const {
            return rhs.getFirst() ^ rhs.getLast() ;
        }
    };

    // 比较相等
    template<>
    struct equal_to<ycpp::Range> {
        typedef ycpp::Range first_argument_type;
        typedef ycpp::Range second_argument_type;
        typedef bool result_type;

        bool operator()(const ycpp::Range &lhs, const ycpp::Range &rhs) const {
            return lhs.getFirst() == rhs.getFirst() &&
                   lhs.getLast() == rhs.getLast();
        }
    };
} // namespace std

#endif //YAUAACPP_RANGE_H
