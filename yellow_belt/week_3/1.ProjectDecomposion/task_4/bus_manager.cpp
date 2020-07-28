#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    for (const auto& stop : stops) {
        buses_to_stops[bus].push_back(stop);
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse busesForStopResponse;
    vector<string> buses;
    if (stops_to_buses.count(stop) > 0)
        buses = stops_to_buses.at(stop);
    busesForStopResponse.buses = buses;
    return busesForStopResponse;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    StopsForBusResponse stopsForBusResponse;
    vector<string> stops;
    if (buses_to_stops.count(bus))
        stops = buses_to_stops.at(bus);
    stopsForBusResponse.stops = stops;
    stopsForBusResponse.stb = stops_to_buses;
    stopsForBusResponse.bus = bus;
    return stopsForBusResponse;
}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse allBusesResponse;
    map<string, vector<string>> stb;
    if (buses_to_stops.size() > 0)
        stb = buses_to_stops;
    allBusesResponse.all_buses = stb;
    return allBusesResponse;
}