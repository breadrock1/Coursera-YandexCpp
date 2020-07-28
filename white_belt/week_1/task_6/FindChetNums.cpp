#include <iostream>
#include "vector"

using namespace std;

vector<int> getAllChets(const int& x, const int& y) {
    vector<int> chet;

    while (x <= y) {
        if (x % 2 == 0) chet.push_back(x);
        x++;
    }

    return chet;
}

int main() {
    int a, b;

    cin >> a >> b;

    if (a > b || a < 1 || b > 30000) exit(0);

    for (const auto& x : getAllChets(a, b)) cout << x << " ";

    return 0;
}
