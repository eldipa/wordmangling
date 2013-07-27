
#include "case.h"
#include <string>

namespace {
char condtoogle(char c, char begin, char end, char offset) {
    if(c >= begin and c <= end)
        return c - begin + offset;
    return c;
}
}


char UpperCase::toupper(char c) {
    return condtoogle(c, 'a', 'z', 'A');
}

UpperCase::UpperCase(int i, int j) : range(i, j) {}

void UpperCase::mangle(std::string &target) {
    for(int i = range.start(target); i <= range.end(target); ++i)
        target[i] = toupper(target[i]);
}


char LowerCase::tolower(char c) {
    return condtoogle(c, 'A', 'Z', 'a');
}

LowerCase::LowerCase(int i, int j) : range(i, j) {}

void LowerCase::mangle(std::string &target) {
    for(int i = range.start(target); i <= range.end(target); ++i)
        target[i] = tolower(target[i]);
}

