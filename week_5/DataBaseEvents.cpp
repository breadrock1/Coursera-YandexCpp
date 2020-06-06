#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <exception>
#include <sstream>
#include <stdexcept>

using namespace std;

class Date {
public:
    explicit Date() {
        year = 0;
        month = 0;
        day = 0;
    };

    explicit Date(const int& inputDay, const int& inputMonth, const int& inputYear) {

        if (inputYear < 1 || inputYear > 31)
            throw runtime_error("Invalid day value");
        else if (inputMonth < 1 || inputMonth > 12)
            throw runtime_error("Invalid month value");

        year = inputYear;
        month = inputMonth;
        day = inputYear;
    };

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

private:
    int day, month, year;
};

bool operator < (const Date& lhs, const Date& rhs) {}

ostream& operator << (ostream& stream, const Date& date) {}

void EnsureNextSymbolAndSkip(stringstream& stream, const string& data_str) {}

istream& operator >> (istream& stream, Date& date) {}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        eventBase[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (eventBase.count(date)) {
            if (eventBase[date].count(event)) {
                eventBase[date].erase(event);
                return true;
            }
        }
        return false;
    }

    int  DeleteDate(const Date& date) {
        if (eventBase.count(date)) {
            eventBase.erase(date);
            return eventBase[date].size();
        }
        return 0;
    }

    void Find(const Date& date) const {
        if (eventBase.count(date)) {
            for (const auto& find : eventBase.at(date)) cout << find << endl;
        }
    }

    void Print() const {
        for (const auto& date : eventBase)
            for (const auto& event : date.second)
                cout << date.first << " " << event << endl;
    }

private:
    map<Date, set<string>> eventBase;
};

void OperationParsing(const string& operation, Database& database) {}


int main() {
    string operation;
    Database database;

    try {

        while (getline(cin, operation))
            OperationParsing(operation, database);

    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}