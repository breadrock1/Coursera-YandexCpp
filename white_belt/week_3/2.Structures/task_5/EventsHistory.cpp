#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct FullName {
    string name;
    string surname;
};

class Person {
public:
    bool isPersonExists(const int& currYear) {
        if (allEvents.empty()) return false;
        int minEventYear = allEvents.begin()->first;
        return minEventYear <= currYear;
    }

    void ChangeFirstName(const int& year, const string& firstName) {
        if (isPersonExists(year) && allEvents.count(year) == 0) allEvents[year].surname = "";
        allEvents[year].name = firstName;
    }

    void ChangeLastName(const int& year, const string& lastName) {
        if (isPersonExists(year) && allEvents.count(year) == 0) allEvents[year].name = "";
        allEvents[year].surname = lastName;
    }

    string GetFullName(int year) {
        if (allEvents.empty()) return "Incognito";

        else if (year < allEvents.begin()->first) return "Incognito";

        else {
            string name, surname;

            for (const auto& event : allEvents) {
                if (event.first <= year && !event.second.name.empty()) name = event.second.name;
                if (event.first <= year && !event.second.surname.empty()) surname = event.second.surname;
            }

            if (name.empty()) return surname + " with unknown first name";
            else if (surname.empty()) return name + " with unknown last name";
            else return name + " " + surname;
        }
    }

private:
    map<int, FullName> allEvents;
};
