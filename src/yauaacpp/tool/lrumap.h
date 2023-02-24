//
// Created by sunxg on 22-2-14.
//

#ifndef YAUAACPP_LRUMAP_H
#define YAUAACPP_LRUMAP_H

#include <map>
#include <string>
#include <iostream>

namespace ycpp {

    template<class K, class V>
    struct lrumap : public std::map<K, V> {
        typedef std::map <K, V> base_type;
        typedef size_t timestamp;
        typedef typename std::map<K, timestamp> K2T;
        typedef typename std::map<timestamp, K> T2K;

        K2T k2t; // from key to timestamp
        T2K t2k; // from timestamp to key

        timestamp tm;
        typename std::map<K, V>::size_type capacity;

        explicit lrumap(size_t cap = 10): tm(1), capacity(cap) {}

        V &operator[](const K &k) {
            timestamp &_tm = k2t[k];
            if (_tm) // if the timestamp already exist, delete it from t2k
                t2k.erase(_tm);
            _tm = tm++; // update timestamp in k2t
            t2k[_tm] = k; // update key in t2k

            V &ret = base_type::operator[](k);

            // remove the oldest if necessary
            if (this->size() > capacity) {
                K k = t2k.begin()->second; // get the eldest key
                erase(k);
            }
            return ret;
        }

        void erase(const K &k) {
            // erase timestamp <-> key reference
            t2k.erase(k2t[k]);
            k2t.erase(k);
            // then the actual data
            base_type::erase(k);
        }
    };
}

#endif //YAUAACPP_LRUMAP_H
