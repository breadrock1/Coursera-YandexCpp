#include <iostream>
#include <string>

using namespace std;

class Incognizable {
public:
    Incognizable() = default;

    Incognizable(const int& x) {
        first = x;
        second = 0;
    }

    Incognizable(const int& x, const int& y) {
        first = x;
        second = y;
    }

private:
    int first, second;
};

int main() {

    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};

    return 0;
}