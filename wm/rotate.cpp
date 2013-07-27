
#include "rotate.h"

Rotate::Rotate(int n) {
    this->n = n<0? -1*n : n;
    this->right = n>=0;
}

void Rotate::mangle(std::string &target) {
    int shift = n % target.length();
    if(right)
        shift = target.length() - shift;

    if(shift)
        target = target.substr(shift) + target.substr(0, shift);
}
