#include <iostream>
#include "string"
#include "vector"

using namespace std;

bool IsPalindrom(const string& check) {
    int size = check.length() - 1;

    for (int i = 0; i <= size ; i++)
        if (check[i] != check[size - i]) return false;

    return true;
}

vector<string> PalindromFilter(vector<string>& words, const int& minLength) {
    vector<string> filtered;

    for (string word : words) {
        if (word.length() < minLength) continue;
        if (IsPalindrom(word)) filtered.push_back(word);
    }

    return filtered;
}

int main() {
    int minLen;
    string input;
    vector<string> words;
    vector<string> filtered;

    do {
        cin >> input;
        input = input.substr(0, input.find(','));
        words.push_back(input);
    } while (cin.peek() != '\n');

    cin >> minLen;

    filtered = PalindromFilter(words, minLen);

    int size = filtered.size() - 1;

    for (int i = 0; i <= size; i++) {
        if (i == size) cout << filtered[i];
        else cout << filtered[i] << ", ";
    }

    return 0;
}
