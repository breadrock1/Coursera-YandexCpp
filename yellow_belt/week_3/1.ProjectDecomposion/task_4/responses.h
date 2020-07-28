#include <ostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
    map<string, vector<string>> stb;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    map<string, vector<string>> all_buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);