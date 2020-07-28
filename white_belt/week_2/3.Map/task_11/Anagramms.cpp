#include <iostream>
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

void ParseInput(vector<string>& str) {
    string input;

    do {
        cin >> input;
        str.push_back(input);
    } while (cin.peek() != '\n');
}

void CheckAnagramm(vector<string>& str) {
    for (string& elem : str) sort(elem.begin(), elem.end());

    (str.at(0) == str.at(1)) ? cout << "YES" : cout << "NO";
    cout << endl;

    str.clear();
}

int main() {
    int numInput;

    cin >> numInput;

    vector<string> anagramm;

    for (int i = 0; i < numInput; ++i) {
        ParseInput(anagramm);
        CheckAnagramm(anagramm);
    }

    return 0;
}
