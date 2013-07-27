#ifndef UPPERCASSE_H_
#define UPPERCASSE_H_

#include "range.h"
#include "mangle.h"
#include <string>

class UpperCase: public Mangle {
private:
    Range range;
    char toupper(char c);

public:
    UpperCase(int i, int j);

protected:
    virtual void mangle(std::string &target);
};

class LowerCase : public Mangle {
private:
    Range range;
    char tolower(char c);

public:
    LowerCase(int i, int j);

protected:
    virtual void mangle(std::string &target);
};

#endif
