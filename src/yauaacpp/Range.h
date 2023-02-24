//
// Created by sunxg on 22-2-23.
//

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
