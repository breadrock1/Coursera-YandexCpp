#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string toLowString(const string& str) {
    string tmp;
    for ( auto s : str) tmp += tolower(s);

    return tmp;
}

int main() {
    int numSymbols;
    string symbol;
    vector<string> allSymbols;

    cin >> numSymbols;

    if (0 > numSymbols || numSymbols > 1000) exit(0);

    for (int i = 0; i < numSymbols; ++i) {
        cin >> symbol;
        allSymbols.push_back(symbol);
    }

    sort(allSymbols.begin(), allSymbols.end(), [](const string& x, const string& y) {
        return toLowString(x) < toLowString(y);
    });

    for (const string& sym : allSymbols) cout << sym << " ";

    return 0;
}

