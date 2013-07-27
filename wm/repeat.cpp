
#include "position.h"
#include "range.h"
#include <string>
#include "repeat.h"

Repeat::Repeat(int i, int j, int times, int p) : range(i,j), times(times), p(p) {}

void Repeat::mangle(std::string &target) {
    int len = range.end(target) - range.start(target) + 1;

    if(len > 0) {
        std::string chunk = target.substr(range.start(target), len);
        for(int i = 0; i < times; ++i)
            target.insert(Position::position(p, target), chunk);
    }
}
