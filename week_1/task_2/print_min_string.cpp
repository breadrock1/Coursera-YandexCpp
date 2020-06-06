#include <iostream>
#include "algorithm"
#include "string"
#include "vector"

using namespace std;

int main() {
    string a,b,c;

    cin >> a >> b >> c;

    if (a.length() > 30 || b.length() > 30 || c.length() > 30)
        exit(0);

    vector<string> strs = {a, b, c};
    sort(begin(strs), end(strs));

    cout << strs[0];

    return 0;
}
