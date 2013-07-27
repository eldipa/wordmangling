
#include "insert.h"
#include "position.h"
#include <string>

Insert::Insert(int p, const std::string &str) : p(p), str(str) {}

void Insert::mangle(std::string &target) {
    target.insert(Position::position(p, target), str);
}
