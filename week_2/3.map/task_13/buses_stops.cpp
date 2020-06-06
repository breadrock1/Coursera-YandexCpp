#include <iostream>
#include "algorithm"
#include "string"
#include "vector"
#include "map"

using namespace std;

void operationAllBuses(const map<string, vector<string>>& routs, vector<string>& buses) {
    if (routs.empty()) cout << "No buses" << endl;
    else {
        for (const auto& rout : routs) {
            cout << "Bus " << rout.first << ":";
            for (const string& stop : rout.second) cout << " " << stop;
            cout << endl;
        }
    }
}

void operationBusesForStop(map<string, vector<string>>& routs, const vector<string>& buses, const string& stop_bus) {
    vector<string> temp;

    for (const auto& rout : routs)
        for (const string& stop : rout.second)
            if (stop == stop_bus) temp.push_back(rout.first);

    if (temp.empty()) cout << "No stop";
    else {
        for (const auto& bus : buses)
            for (const string& stop : temp)
                if (bus == stop) cout << bus << " ";
    }

    cout << endl;
}

void operationStopForBus(map<string, vector<string>>& routs, vector<string> buses,  const string& bus_stop) {
    int count = 0;

    for (const auto& rout : routs) {
        if (rout.first == bus_stop) {
            for (const auto& stop : rout.second) {
                cout << "Stop " << stop << ":";

                vector<string> temp;

                for (const auto& elem : routs) {
                    for (const auto& el : elem.second) {
                        if (el == stop && elem.first != bus_stop) {
                            temp.push_back(elem.first);
                        }
                    }
                }
                if (temp.empty()) {
                    cout << " no interchange";
                } else {
                    for (const auto& bus : buses) {
                        for (const auto& bstop : temp) {
                            if (bstop == bus) {
                                cout << " " << bus;
                            }
                        }
                    }
                }
                cout << endl;
            }
            count++;
        }
    }

    if (count == 0) cout << "No bus" << endl;
}

int main() {
    int numOperations, stop_count;
    string typeOperation, input_stop, busName, stopName;

    cin >> numOperations;

    vector<string> allBuses;
    map<string, vector<string>> allBusesRouts;

    for (int i = 0; i < numOperations; ++i) {
        cin >> typeOperation;

        if (typeOperation == "NEW_BUS") {

            cin >> busName >> stop_count;
            allBuses.push_back(busName);

            for (int i = 0; i < stop_count; i++) {
                cin >> input_stop;
                allBusesRouts[busName].push_back(input_stop);
            }

        } else if (typeOperation == "BUSES_FOR_STOP") {
            cin >> stopName;
            operationBusesForStop(allBusesRouts, allBuses, stopName);
        } else if (typeOperation == "STOPS_FOR_BUS") {
            cin >> busName;
            operationStopForBus(allBusesRouts, allBuses, busName);
        } else if (typeOperation == "ALL_BUSES") operationAllBuses(allBusesRouts, allBuses);
        else exit(0);
    }

    return 0;
}
