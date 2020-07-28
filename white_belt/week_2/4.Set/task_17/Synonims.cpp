#include <iostream>
#include "string"
#include "set"
#include "map"

using namespace std;

void OperationCOUNT(const map<string, set<string>>& words, const string& word1) {
    (words.count(word1)) ? cout << words.at(word1).size() : cout << "0";
    cout << endl;
}

void OperationCHECK(map<string, set<string>>& words, const string& word1, const string& word2) {
    if (words[word1].count(word2) == 1) cout << "YES";
    else cout << "NO";

    cout << endl;
}

void OperationADD(map<string, set<string>>& words, const string& word1, const string& word2) {
    words[word1].insert(word2);
    words[word2].insert(word1);
}

int main() {
    int numRequests;
    string typeOperation, word1, word2;;
    map<string, set<string>> synonims;

    cin >> numRequests;

    for (int i = 0; i < numRequests; i++) {
        cin >> typeOperation;

        if (typeOperation == "ADD") {
            cin >> word1 >> word2;
            OperationADD(synonims, word1, word2);
        } else if (typeOperation == "COUNT") {
            cin >> word1;
            OperationCOUNT(synonims, word1);
        } else if (typeOperation == "CHECK") {
            cin >> word1 >> word2;
            OperationCHECK(synonims, word1, word2);
        } else exit(0);
    }

    return 0;
}