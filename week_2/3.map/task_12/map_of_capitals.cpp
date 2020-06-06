#include <iostream>
#include "string"
#include "map"

using namespace std;

void operationChangeCapital(map<string, string>& capitals, const string& country, const string& newCapital) {

    if (capitals.find(country) == capitals.end()) {
        capitals[country] = newCapital;
        cout << "Introduce new country " << country << " with capital " << newCapital << endl;
    } else if (capitals.at(country) == newCapital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
        cout << "Country " << country << " has changed its capital from " << capitals.at(country) << " to " << newCapital << endl;
        capitals.at(country) = newCapital;
    }

}

void operationRename(map<string, string>& capitals, string& oldCountry, const string& newCountry) {

    if (oldCountry == newCountry || capitals.find(oldCountry) == capitals.end() || capitals.find(newCountry) != capitals.end())
        cout << "Incorrect rename, skip" << endl;
    else {
        capitals[newCountry] = capitals.at(oldCountry);
        cout << "Country " << oldCountry << " with capital " << capitals.at(oldCountry) << " has been renamed to " << newCountry << endl;
        capitals.erase(oldCountry);
    }

}

void operationAbout(const map<string, string>& capitals, const string& country) {

    if (capitals.empty() || capitals.find(country) == capitals.end())
        cout << "Country " << country << " doesn't exist" << endl;
    else
        cout << "Country " << country << " has capital " << capitals.at(country) << endl;
}

void operationDump(const map<string, string>& capitals) {
    if (capitals.empty())
        cout << "There are no countries in the world" << endl;
    else
        for (const auto& country : capitals)
            cout << country.first << "/" << country.second << " ";

    cout << endl;
}

void ParseInput(string& operation, string& first, string& second) {
    int count = 0;
    string input;

    do {
        cin >> input;
        if (count == 0) operation = input;
        if (count == 1) first = input;
        if (count == 2) second = input;

        count++;
    } while (cin.peek() != '\n');
}

int main() {
    int numRequests;
    string typeOperation, firstArg, secondArg;
    map<string, string> countries;

    cin >> numRequests;

    for (int i = 0; i < numRequests; ++i) {
        ParseInput(typeOperation, firstArg, secondArg);

        if (typeOperation == "DUMP") operationDump(countries);
        else if (typeOperation == "ABOUT") operationAbout(countries, firstArg);
        else if (typeOperation == "RENAME") operationRename(countries, firstArg, secondArg);
        else if (typeOperation == "CHANGE_CAPITAL") operationChangeCapital(countries, firstArg, secondArg);
        else exit(0);
    }

    return 0;
}