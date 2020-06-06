#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    string input;
    int numRequests, numStops;
    map<vector<string>, int> buses;

    cin >> numRequests;

    for (int i = 0; i < numRequests; ++i) {

        cin >> numStops;
        vector<string> stops;

        for (int j = 0; j < numStops; ++j) {
            cin >> input;
            stops.push_back(input);
        }

        if (buses.count(stops)) cout << "Already exists for " << buses[stops];
        else {
            buses[stops] = buses.size() + 1;
            cout << "New bus " << buses[stops];
        }

        cout << endl;

    }

    return 0;
}