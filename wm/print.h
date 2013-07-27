#ifndef PRINT_H_
#define PRINT_H_

#include "mangle.h"
#include <iosfwd>
#include <string>

class Print : public Mangle {
private:
    std::ostream &out;

public:
    Print(std::ostream &out);

protected:
    virtual void mangle(std::string &target);
};

#endif
