#ifndef REPEAT_H_
#define REPEAT_H_

#include "range.h"
#include "mangle.h"
#include <string>

class Repeat : public Mangle {
private:
    Range range;
    int times;
    int p;

public:
    Repeat(int i, int j, int times, int p);

protected:
    virtual void mangle(std::string &target);
};

#endif

