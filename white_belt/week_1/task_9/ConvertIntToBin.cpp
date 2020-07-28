#include <iostream>
#include "vector"

using namespace std;

int main() {
    int n;
    vector<int> binary;

    cin >> n;

    while (n > 0) {
        binary.push_back(n % 2);
        n /= 2;
    }

    for (vector<int>::reverse_iterator it = binary.rbegin(); it != binary.rend(); ++it)
        cout << *it;

    return 0;
}
