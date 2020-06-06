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
    void ChangeFirstName(int year, const string& first_name) {
        allEvents[year].name = first_name;
        allEvents[year].surname = "";
    }

    void ChangeLastName(int year, const string& last_name) {
        allEvents[year].name = "";
        allEvents[year].surname = last_name;
    }

    string GetFullName(int year) {
        if (allEvents.empty()) return "Incognito";

        else if (allEvents.begin()->first > year) return "Incognito";

        else {
            string name, surname;

            for (const auto& event : allEvents) {
                if (event.first <= year && !event.second.name.empty()) name = event.second.name;
                if (event.first <= year && !event.second.surname.empty()) surname = event.second.surname;
            }

            if (name.empty()) return name + " with unknown first name";
            else if (surname.empty()) return surname + " with unknown last name";
            else return name + " " + surname;
        }
    }

private:
    map<int, FullName> allEvents;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

