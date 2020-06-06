#include <iostream>
#include "string"
#include "set"

using namespace std;

int countUniqStrings(set<string>& mas) {
    return mas.size();
}

int main() {
    int numStrings;
    string input;
    set<string> words;

    cin >> numStrings;

    for (int i = 0; i < numStrings; ++i) {
        cin >> input;
        words.insert(input);
    }

    cout << countUniqStrings(words);

    return 0;
}