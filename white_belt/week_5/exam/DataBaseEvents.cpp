#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <exception>
#include <sstream>
#include <stdexcept>

using namespace std;

class Date {
public:
    explicit Date() {
        day = 0;
        month = 0;
        year = 0;
    };

    explicit Date(const int& inputDay, const int& inputMonth, const int& inputYear) {

        if (inputMonth < 1 || inputMonth > 12)
            throw runtime_error("Month value is invalid: " + to_string(inputMonth));
        else if (inputDay < 1 || inputDay > 31)
            throw runtime_error("Day value is invalid: " + to_string(inputDay));

        day = inputDay;
        month = inputMonth;
        year = inputYear;
    };

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }

private:
    int day, month, year;
};

bool operator < (const Date& first, const Date& second);
ostream& operator << (ostream& stream, const Date& date);
istream& operator >> (istream& inputStream, Date& date);

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
            int countEvents = eventBase[date].size();
            eventBase.erase(date);
            return countEvents;
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
            for (const auto& event : date.second) cout << date.first << " " << event << endl;
    }

private:
    map<Date, set<string>> eventBase;
};



bool operator < (const Date& first, const Date& second) {
    if ((first.getMonth() == second.getMonth()) && (first.getYear() == second.getYear()))
        return first.getDay() < second.getDay();
    else if ((first.getMonth() != second.getMonth()) && (first.getYear() == second.getYear()))
        return first.getMonth() < second.getMonth();

    return first.getYear() < second.getYear();
}

ostream& operator << (ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.getYear() << '-'
           << setw(2) << setfill('0') << date.getMonth() << '-'
           << setw(2) << setfill('0') << date.getDay();

    return stream;
}

void ignoring(stringstream& inputStream, const string& input) {
    if (inputStream.peek() != '-')
        throw runtime_error("Wrong date format: " + input);
    inputStream.ignore(1);
}

istream& operator >> (istream& inputStream, Date& date) {
    int day, month, year;
    day = month = year = 10000;

    string input, end;

    if (inputStream >> input) {
        stringstream stream(input);

        stream >> year;
        ignoring(stream, input);

        stream >> month;
        ignoring(stream, input);

        stream >> day;
        stream >> end;

        if (year > -1 && year < 10000 && month < 10000 && day < 10000 && end.empty()) {
            date = Date(day, month, year);
            return inputStream;
        } else throw runtime_error("Wrong date format: " + input);

    } else throw runtime_error("Wrong date format: " + input);
}

void OperationParser(const string& operat, Database& database) {
    Date date;
    stringstream stream(operat);
    string event, operation = operat;

    if (stream >> operation) {
        if (operation == "Add") {
            if (stream >> date) {
                if (stream >> event) database.AddEvent(date, event);
                else {
                    stringstream input;
                    input << "Wrong date format: " << date;
                    throw runtime_error(input.str());
                }
            }
        }

        else if (operation == "Find") {
            if (stream >> date) database.Find(date);
        }

        else if (operation == "Print") database.Print();

        else if (operation == "Del") {
            if (stream >> date) {
                if (stream >> event) {
                    if (database.DeleteEvent(date, event)) cout << "Deleted successfully" << endl;
                    else cout << "Event not found" << endl;
                } else {
                    cout << "Deleted " << database.DeleteDate(date) << " events" << endl;
                }

            }
        }

        else throw runtime_error("Unknown command: " + operation);
    }
}



int main() {
    Database db;
    string command;

    try {
        while (getline(cin, command))
            OperationParser(command, db);
    } catch (exception& e) {
        cout << e.what();
    }

    return 0;
}