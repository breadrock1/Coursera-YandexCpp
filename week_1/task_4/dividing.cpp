#include <iostream>
#include "cmath"

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    if ((a < 0 || b < 0) || (a > 1000000 || b > 1000000))
        exit(0);

    if (b == 0) {
        cout << "Impossible";
        return 0;
    }

    cout << a / b;

    return 0;
}
