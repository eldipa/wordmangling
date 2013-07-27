#ifndef RANGE_H_
#define RANGE_H_

#include "position.h"

class Range {
private:
    int i, j;

public:
    Range(int i, int j) : i(i), j(j) {}

    int start(const std::string& target) {
        return Position::position(i, target, true);
    }

    int end(const std::string & target) {
        return Position::position(j, target, false);
    }

    /*
     * for(int i = start(...); i <= end(...); ++i) {
     *    ...
     * }
     *
     * azul   i=0  j=2
     * i j    for  i=0  to  j=2  --> azu
     *
     * azul   i=-2 j=3
     *   ij   for  i=2  to  j=3  --> ul
     *
     * azul   i=0  j=-1
     * i  j   for  i=0  to  j=3  --> azul
     *
     * azul   i=-3 j=-2
     *  ij    for  i=1  to  j=2  --> zu
     *
     * azul   i=-1 j=-2
     *   ji   for  i=3  to  j=2  -->
     *
     * azul   i=0  j=9
     * i  j   for  i=0  to  j=3  --> azul
     *
     * azul   i=9  j=2
     *   j    for  i=4  to  j=2  -->
     *
     * azul   i=9  j=10
     *        for  i=4  to  j=3  -->
     *
     * azul   i=-9 j=10
     *        for  i=0  to  j=3  --> azul
     *
     * azul   i=9  j=-9
     *        for  i=4  to  j=-1 -->
     * */

};

#endif
