#include "rules.h"

#include "repeat.h"
#include "case.h"
#include "insert.h"
#include "print.h"
#include "rotate.h"
#include "revert.h"

#include <istream>
#include <list>

class Mangle;

Rules::Rules(std::ostream &out) : out(out) {}

std::istream& Rules::load(std::istream &in) {
    while(not in.eof()) {
        std::string keyword;
        Mangle *rule = 0;
        char c = 0;
        in >> keyword;

        if(in.eof())
            continue;

        if(keyword == "uppercase" or keyword == "lowercase") {
            int n, m;
            in >> n >> m;
            if(keyword == "uppercase")
                rule = new UpperCase(n,m);
            else
                rule = new LowerCase(n,m);
        }
        else if(keyword == "repeat") {
            int n, m, r, i;
            in >> n >> m >> r >> i;
            rule = new Repeat(n, m, r, i);
        }
        else if(keyword == "rotate") {
            int n;
            in >> n;
            rule = new Rotate(n);
        }
        else if(keyword == "insert") {
            int n;
            std::string payload;
            in >> n >> payload;
            rule = new Insert(n, payload);
        }
        else if(keyword == "revert") {
            int n;
            in >> n;
            --n;
            std::list<Mangle*>::reverse_iterator it = rules.rbegin();
            while (n > 0) {
                ++it;
                --n;
            }

            (*it)->save_copy();
            rule = new Revert(rules, (**it));
        }
        else if(keyword == "print") {
            rule = new Print(out);
        }
        else {
            throw "b";
        }

        rules.push_back(rule);

        in >> std::ws >> c;
        if(c != ';')
            throw "c";
    }
    return in;
}

void Rules::mangle_words(std::istream &in) {
    std::string line;
    getline(in, line);
    while(not in.eof()) {
        mangle(line);
        getline(in, line);
    }
}

void Rules::mangle(std::string &target) {
    for(std::list<Mangle*>::iterator it = rules.begin(); it != rules.end(); ++it)
        (*it)->mangle_word(target);
}

Rules::~Rules() {
    for(std::list<Mangle*>::iterator it = rules.begin(); it != rules.end(); ++it)
        delete *it;
}


std::istream& operator>>(std::istream &in, Rules &r) {
    return r.load(in);
}
