#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& stream, Query& query) {
    string command;
    stream >> command;
    if (command == "NEW_BUS") {
        query.type = QueryType::NewBus;
        stream >> query.bus;
        int stops_count;
        stream >> stops_count;
        query.stops.resize(stops_count);
        for (auto& stop : query.stops)
            stream >> stop;
    } else if (command == "BUSES_FOR_STOP") {
        query.type = QueryType::BusesForStop;
        stream >> query.stop;
    } else if (command == "STOPS_FOR_BUS") {
        query.type = QueryType::StopsForBus;
        stream >> query.bus;
    } else {
        query.type = QueryType::AllBuses;
    }
    return stream;
}

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator << (ostream& stream, const BusesForStopResponse& response) {
    if (response.buses.empty())
        stream << "No stop";
    else {
        for (const auto& bus : response.buses)
            stream << bus << ' ';
    }
    stream << endl;
    return stream;
}

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
    map<string, vector<string>> stb;
};

ostream& operator << (ostream& stream, const StopsForBusResponse& response) {
    if (response.stops.empty())
        stream << "No bus" << endl;
    else {
        for (const auto& stop : response.stops) {
            stream << "Stop " << stop << ": ";
            auto bs = response.stb.at(stop);
            if (bs.size() == 1)
                stream << "no interchange";
            else {
                for (const string& other_bus : bs) {
                    if (other_bus != response.bus)
                        stream << other_bus << ' ';
                }
            }
            stream << endl;
        }
    }
    return stream;
}

struct AllBusesResponse {
    map<string, vector<string>> all_buses;
};

ostream& operator << (ostream& stream, const AllBusesResponse& response) {
    if (response.all_buses.empty())
        stream << "No buses" << endl;
    else {
        for (const auto& bus_item : response.all_buses) {
            stream << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                stream << stop << " ";
            }
            stream << endl;
        }
    }
    return stream;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        for (const auto& stop : stops) {
            buses_to_stops[bus].push_back(stop);
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse busesForStopResponse;
        vector<string> buses;
        if (stops_to_buses.count(stop) > 0)
            buses = stops_to_buses.at(stop);
        busesForStopResponse.buses = buses;
        return busesForStopResponse;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse stopsForBusResponse;
        vector<string> stops;
        if (buses_to_stops.count(bus))
            stops = buses_to_stops.at(bus);
        stopsForBusResponse.stops = stops;
        stopsForBusResponse.stb = stops_to_buses;
        stopsForBusResponse.bus = bus;
        return stopsForBusResponse;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse allBusesResponse;
        map<string, vector<string>> stb;
        if (buses_to_stops.size() > 0)
            stb = buses_to_stops;
        allBusesResponse.all_buses = stb;
        return allBusesResponse;
    }
private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};

bool operator==(const Query& lhs, const Query& rhs) {
    return lhs.bus == rhs.bus && lhs.stop == rhs.stop && lhs.type == rhs.type && lhs.stops == rhs.stops;
}

int main() {
    int query_count;
    Query q;
    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}
