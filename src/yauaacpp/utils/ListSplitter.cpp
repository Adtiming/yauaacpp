//
// Created by sunxg on 22-2-5.
//

#include "ListSplitter.h"

namespace ycpp {
    std::mutex ListSplitter::lock;

    ListSplitter * ListSplitter::instance = nullptr;

    ListSplitter *ListSplitter::getInstance() {
        if (instance == nullptr) {
            lock.lock();
            if(instance == nullptr)
                instance = new ListSplitter();
            lock.unlock();
        }
        return instance;
    }

}