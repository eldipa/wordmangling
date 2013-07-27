
#include "position.h"
#include <string>

namespace Position {
int position(int i, const std::string &target, bool flag) {
    int len = int(target.length());
    if(len <= 0)
        throw 2;

    if(i >= 0) {
        if(i < len)
            return i;
        else
            return (not flag)? len - 1 : len;
    }
    else {
        if(-1*i <= len)
            return len + i;
        else
            return flag? 0 : -1;
    }
}

int position(int i, const std::string &target) {
    return i<0? position(i, target, true)+1 : position(i, target, false);
}
}

