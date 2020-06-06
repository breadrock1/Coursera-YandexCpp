#include <iostream>
#include "cmath"

using namespace std;

double getDescriminant(double a, double b, double c) {
    return sqrt((b * b) - (4 * a * c));
}

int main() {
    double a, b, c, d;

    cin >> a >> b >> c;

    if (a == 0 & b != 0) {
        cout << (-c) / b;
        return 0;
    } else if (a == b & b == 0)
        exit(0);

    d = getDescriminant(a, b, c);

    if (d == 0) cout << (-b) / (2 * a);
    else if (d > 0) cout << ((-b) + d) / (2 * a) << " " << ((-b) - d) / (2 * a);
    else exit(0);

    return 0;
}
