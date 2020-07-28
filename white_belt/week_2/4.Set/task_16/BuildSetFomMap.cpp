#include "map"
#include "set"

using namespace std;

set<string> BuildSetFromMap(const map<int, string>& m) {
    set<string> newset;

    for (const auto& elem : m) newset.insert(elem.second);

    return newset;
}