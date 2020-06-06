#include <iostream>
#include "vector"

using namespace std;

int main() {
    int n;
    vector<int> bin_num;

    cin >> n;

    while (n > 0) {
        bin_num.push_back(n % 2);
        n /= 2;
    }

    for (vector<int>::reverse_iterator it = bin_num.rbegin(); it != bin_num.rend(); it++)
        cout << *it;

    return 0;
}
