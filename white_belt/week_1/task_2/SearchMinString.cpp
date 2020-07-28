#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void getMinNum(const vector<string>& vec) {
    sort(begin(vec), end(vec));

    cout << vec[0];
}

int main() {
    string a, b, c;

    cin >> a >> b >> c;

    if (a.length() > 30 || b.length() > 30 || c.length() > 30)
        exit(0);

    vector<string> strs = { a, b, c };

    getMinNum(strs);

    return 0;
}
