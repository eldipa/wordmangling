#ifndef MANGLE_H_
#define MANGLE_H_

#include <string>

class Mangle {
private:
    std::string copy;

public:
    bool make_copy;
    Mangle();
    virtual ~Mangle();

    void save_copy();
    void mangle_word(std::string &target);
    const std::string get_copy() const;

protected:
    virtual void mangle(std::string &target) = 0;
};

#endif
