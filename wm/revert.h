#ifndef REVERT_H_
#define REVERT_H_

#include "mangle.h"
#include <list>

class Revert: public Mangle {
private:
    const std::list<Mangle*> &rules;
    const Mangle &revert_target;

public:
    Revert(const std::list<Mangle*> &rules, const Mangle &revert_target) :
        rules(rules), revert_target(revert_target) {
    }

protected:
    virtual void mangle(std::string &target) {
        target = revert_target.get_copy();
    }
};

#endif
