//
// Created by sunxg on 22-2-13.
//

#ifndef YAUAACPP_BUILDER_H
#define YAUAACPP_BUILDER_H


template <typename T>
class Builder{
    T * obj;
    T * build(){ return obj;}
};

class Builderable {
    virtual ~Builderable(){}
    friend class Builder<Builderable>;
};

#endif //YAUAACPP_BUILDER_H
