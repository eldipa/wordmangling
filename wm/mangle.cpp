
#include <string>
#include "mangle.h"

Mangle::Mangle() : make_copy(false) {}
Mangle::~Mangle() {}

void Mangle::save_copy() {
    make_copy = true;
}

void Mangle::mangle_word(std::string &target) {
    if(make_copy)
        copy = target;

    mangle(target);
}

const std::string Mangle::get_copy() const {
    if(not make_copy)
        throw "Not copy available";

    return copy;
}

