#ifndef RULES_H_
#define RULES_H_

#include <list>
#include <iosfwd>

class Mangle;

class Rules {
private:
    std::list<Mangle*> rules;
    std::ostream &out;

public:
    Rules(std::ostream &out);
    std::istream& load(std::istream &in);
    void mangle_words(std::istream &in);
    void mangle(std::string &target);
    ~Rules();
};


std::istream& operator>>(std::istream &in, Rules &r);

#endif
