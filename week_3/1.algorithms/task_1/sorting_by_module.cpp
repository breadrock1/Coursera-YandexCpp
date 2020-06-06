#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int numNumbers, input;
    vector<int> allNumbers;

    cin >> numNumbers;

    if (0 > numNumbers || numNumbers > 1000) exit(0);

    for (int i = 0; i < numNumbers; ++i) {
        cin >> input;
        allNumbers.push_back(input);
    }

    sort(allNumbers.begin(), allNumbers.end(), [](const int& a, const int& b) {
        return abs(a) < abs(b);
    });

    for (const int& num : allNumbers) cout << num << " ";

    return 0;
}

