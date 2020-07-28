#include "query.h"
#include "responses.h"

#include <ostream>

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty())
        os << "No stop";
    else {
        for (const auto& bus : r.buses)
            os << bus << ' ';
    }
    os << endl;
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty())
        os << "No bus" << endl;
    else {
        for (const auto& stop : r.stops) {
            os << "Stop " << stop << ": ";
            auto bs = r.stb.at(stop);
            if (bs.size() == 1)
                os << "no interchange";
            else {
                for (const string& other_bus : bs) {
                    if (other_bus != r.bus)
                        os << other_bus << ' ';
                }
            }
            os << endl;
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.all_buses.empty())
        os << "No buses" << endl;
    else {
        for (const auto& bus_item : r.all_buses) {
            os << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                os << stop << " ";
            }
            os << endl;
        }
    }
    return os;
}

bool operator==(const Query& lhs, const Query& rhs) {
    return lhs.bus == rhs.bus && lhs.stop == rhs.stop && lhs.type == rhs.type && lhs.stops == rhs.stops;
}