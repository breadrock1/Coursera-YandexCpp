#include <iostream>

using namespace std;

int getDiv(int x, int y) {
    return y ? getDiv(y, x % y) : x;
}

int main() {
    int a, b;

    cin >> a >> b;

    cout << getDiv(a, b);

    return 0;
}
