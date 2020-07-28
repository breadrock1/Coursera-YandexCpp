#include <iostream>
#include "string"
#include "vector"

using namespace std;

void OperationCome(vector<int>& vec, const int& key) {
    int count = abs(key);
    for (int i = 0; i < count; i++) (key > 0) ? vec.push_back(0) : vec.pop_back();
}

void OperationWorry(vector<int>& vec, const int& key) {
    vec[key] = 1;
}

void OperationQuiet(vector<int>& vec, const int& key) {
    vec[key] = 0;
}

void OperationWorryCount(vector<int>& vec) {
    int worriedSize = 0;
    for (int status : vec) (status == 1) ? worriedSize++ : worriedSize += 0;
    cout << worriedSize << endl;
}

void parseInput(string& operation, int& key) {
    string input;
    int count = 0;

    do {
        cin >> input;

        if (count == 0) operation = input;
        else key = atoi(input.c_str());

        count++;
    } while (cin.peek() != '\n');
}

int main() {
    int numOperations, numHuman;
    string typeOperation;
    vector<int> turnOfPeople;

    cin >> numOperations;

    for (int i = 0; i < numOperations; i++) {
        parseInput(typeOperation, numHuman);

        if (typeOperation == "COME") OperationCome(turnOfPeople, numHuman);
        else if (typeOperation == "WORRY") OperationWorry(turnOfPeople, numHuman);
        else if (typeOperation == "QUIET") OperationQuiet(turnOfPeople, numHuman);
        else if (typeOperation == "WORRY_COUNT") OperationWorryCount(turnOfPeople);
        else exit(0);
    }

    return 0;
}
