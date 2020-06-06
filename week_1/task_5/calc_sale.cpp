#include <iostream>
#include "cmath"

using namespace std;

float getSale(float n, float z) {
    return (n - ((n * z) / 100));
}

int main() {
    float n, a, b, x, y;

    cin >> n >> a >> b >> x >> y;

    if (a >= b) exit(0);

    if (n > b) n = getSale(n, y);
    else if (n > a & n <= b) n = getSale(n, x);
    else if (n > a & n >= b) {
        n = getSale(n, x);
        n = getSale(n, y);
    }

    cout << n;

    return 0;
}
