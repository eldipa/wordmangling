#ifndef INSERT_H_
#define INSERT_H_

#include "mangle.h"
#include <string>

class Insert: public Mangle {
private:
    int p;
    std::string str;

public:
    Insert(int p, const std::string &str);

protected:
    virtual void mangle(std::string &target);
};

#endif
