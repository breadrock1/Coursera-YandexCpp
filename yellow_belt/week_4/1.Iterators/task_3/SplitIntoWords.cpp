#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    string tmp_word;
    vector<string> splited_words;

    for (auto it = s.begin(); it != s.end(); ++it) {

        if (*it == ' ') {
            splited_words.push_back(tmp_word);
            tmp_word.clear();
            continue;
        } else {
            tmp_word += *it;
        }
    }

    splited_words.push_back(tmp_word);

    return splited_words;
}

int main() {
    string s = "C Cpp Java Python";
    vector<string> words = SplitIntoWords(s);

    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}