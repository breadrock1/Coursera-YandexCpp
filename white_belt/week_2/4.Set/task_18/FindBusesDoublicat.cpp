#include <iostream>
#include <set>
#include <map>
#include "string"

using namespace std;

void checkRoutersExisting(map<int, set<string>>& routs, const set<string>& curr_routs) {
    int id, flag = 0;

    for (const auto& rout : routs)
        if (rout.second == curr_routs) {
            id = rout.first;
            flag++;
            break;
        }

    if (flag == 0) {
        id = routs.size() + 1;
        routs[id] = curr_routs;
        cout << "New bus " << id;
    } else cout << "Already exists for " << id;

    cout << endl;
}

int main() {
    int numRequests, numStops;
    string input;
    map<int, set<string>> busesStops;

    cin >> numRequests;

    for (int i = 0; i < numRequests; ++i) {

        cin >> numStops;

        set<string> currStops;

        for (int j = 0; j < numStops; ++j) {
            cin >> input;
            currStops.insert(input);
        }

        checkRoutersExisting(busesStops, currStops);
    }

    return 0;
}