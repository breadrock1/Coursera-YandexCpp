#include <iostream>

using namespace std;

int getGreatestCommonDivisor(const int& x, const int& y) {
    return y ? getGreatestCommonDivisor(y, x % y) : x;
}

int main() {
    int a, b;

    cin >> a >> b;

    cout << getGreatestCommonDivisor(a, b);

    return 0;
}
