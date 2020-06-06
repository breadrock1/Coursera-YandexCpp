#include <iostream>
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
    Person() = default;

    Person(const string& firstName, const string& lastName, const int& year) {
        minYear = year;
        allEvents[year] = { firstName, lastName };
        for (const auto& event : allEvents)
            if (event.first < year) allEvents.erase(event.first);
    }

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

    string GetFullName(const int& year) {
        if (allEvents.empty() || year < allEvents.begin()->first) return "Incognito";

        string firstName, lastName;

        for (const auto &event : allEvents) {
            if (event.first <= year && !event.second.name.empty()) firstName = event.second.name;
            if (event.first <= year && !event.second.surname.empty()) lastName = event.second.surname;
        }

        if (firstName.empty()) return lastName + " with unknown first name";
        else if (lastName.empty()) return firstName + " with unknown last name";
        else return firstName + " " + lastName;
    }

    string GetFullNameWithHistory(int year) {
        if (allEvents.empty() || minYear != 0 && minYear > year) return "Incognito";
        else
            if (!isPersonExists(year)) return "Incognito";

        string firstName, lastName;
        vector<string> allFirstNames, allLastNames;

        for (const auto& event : allEvents) {
            if (event.first <= year && !event.second.name.empty()) {
                if (event.second.name != firstName && !firstName.empty()) allFirstNames.push_back(firstName);
                firstName = event.second.name;
            }
            if (event.first <= year && !event.second.surname.empty()) {
                if (event.second.surname != lastName && !lastName.empty()) allLastNames.push_back(lastName);
                lastName = event.second.surname;
            }
        }

        string firstout, lastout;

        if (allFirstNames.size() > 0) {
            firstout += " (" + allFirstNames[allFirstNames.size() - 1];
            if (allFirstNames.size() > 1) {
                for (int i = allFirstNames.size() - 1; i > 0; --i) {
                    firstout += ", " + allFirstNames[i - 1];
                }
            }
            firstout += ")";
        }

        if (allLastNames.size() > 0) {
            lastout += " (" + allLastNames[allLastNames.size() - 1];
            if (allLastNames.size() > 1) {
                for (int i = allLastNames.size() - 1; i > 0; --i) {
                    lastout += ", " + allLastNames[i - 1];
                }
            }
            lastout += ")";
        }

        if (firstName.empty()) return lastName + lastout + " with unknown first name";
        else if (lastName.empty()) return firstName + firstout + " with unknown last name";
        else return firstName + firstout + " " + lastName + lastout;
    }

private:
    map<int, FullName> allEvents;
    int minYear = 0;
};
