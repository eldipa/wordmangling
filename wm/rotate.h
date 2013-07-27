#ifndef ROTATE_H_
#define ROTATE_H_

#include "mangle.h"
class Rotate : public Mangle {
private:
    int n;
    bool right;

public:
    Rotate(int n);

protected:
    virtual void mangle(std::string &target);
};

#endif
