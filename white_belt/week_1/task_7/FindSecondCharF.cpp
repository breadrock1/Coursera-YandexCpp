#include <iostream>
#include <vector>
#include "string"
#include "map"

using namespace std;

int main() {
    string mainstring;
    vector<int> f_chars;

    cin >> mainstring;

    for (int i = 0; i <= mainstring.length(); i++)
        if (mainstring[i] == 'f') f_chars.push_back(i);

    int size = f_chars.size();

    switch (size) {
        case 0:
            cout << -2;
            break;
        case 1:
            cout << -1;
            break;
        default:
            cout << f_chars[1];
    }

    return 0;
}
