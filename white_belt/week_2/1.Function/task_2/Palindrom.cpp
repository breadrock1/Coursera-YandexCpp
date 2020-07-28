#include <iostream>
#include "string"

using namespace std;

bool isPalindrom(const string& check) {
    int size = check.length() - 1;

    for (int i = 0; i <= size ; i++)
        if (check[i] != check[size - i]) return false;

    return true;
}

int main() {
    string input;

    cin >> input;

    if (input == "") cout << "true";
    else isPalindrom(input) ? cout << "true" : cout << "false";

    return 0;
}
