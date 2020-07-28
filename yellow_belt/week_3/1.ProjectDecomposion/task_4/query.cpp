#include "query.h"

#include <istream>
#include <string>

using namespace std;

istream& operator >> (istream& is, Query& q) {
    string command;
    is >> command;
    if (command == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stops_count;
        is >> stops_count;
        q.stops.resize(stops_count);
        for (auto& stop : q.stops)
            is >> stop;
    } else if (command == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (command == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else {
        q.type = QueryType::AllBuses;
    }
    return is;
}