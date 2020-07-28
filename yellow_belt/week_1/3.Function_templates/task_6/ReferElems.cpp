#include <iostream>
#include <exception>
#include <string>
#include <map>

using namespace std;

template <typename mapKey, typename mapValue, typename inputKey>
mapValue& GetRefStrict(map<mapKey, mapValue> &m, inputKey k) {
    if (m.count(k) > 0) return m[k];
    else throw(runtime_error("Error"));
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;

    return 0;
}