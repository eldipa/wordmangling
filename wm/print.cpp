
#include "print.h"
#include <ostream>

Print::Print(std::ostream &out) : out(out) {}

void Print::mangle(std::string &target) {
    out << target << std::endl;
}
