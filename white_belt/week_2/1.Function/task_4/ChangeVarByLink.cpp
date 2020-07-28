#include <iostream>

using namespace std;

void UpdateIfGreater(int& first, int& second) {
    (first > second) ? second = first : second = second;
}

int main() {
    int a, b;

    cin >> a >> b;

    UpdateIfGreater(a, b);

    cout << a << b;

    return 0;
}
