#include <iostream>
#include "vector"
#include "string"

using namespace std;

void PrintElements(const vector<string>& vec) {
    for (string elem : vec) cout << elem << " ";
}

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (string elem : source) destination.push_back(elem);
    source.clear();
}

int main() {
    string input;
    vector<string> first;
    vector<string> second;

    do {
        cin >> input;
        first.push_back(input);
    } while (cin.peek() != '\n');

    do {
        cin >> input;
        second.push_back(input);
    } while (cin.peek() != '\n');

    MoveStrings(first, second);
    PrintElements(second);

    return 0;
}
