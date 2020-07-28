#include <iostream>
#include <set>
#include "string"
#include "vector"

using namespace std;

vector<vector<string>> operationNEXT(vector<vector<string>>& currMonth, const int& days) {
    vector<vector<string>> newMonth;
    newMonth = currMonth;
    newMonth.resize(days);

    if (currMonth.size() > days) {
        for (int i = days - 1; i < currMonth.size(); i++)
            newMonth.at(days - 1).insert(newMonth.at(days - 1).end(), currMonth.at(i).begin(), currMonth.at(i).end());

        set<string> temp(newMonth.at(days - 1).begin(), newMonth.at(days - 1).end());
        newMonth.at(days - 1).assign(temp.begin(), temp.end());
    }

    currMonth.clear();

    return newMonth;
}

void operationDUMP(vector<vector<string>>& month, const int& day) {
    cout << month.at(day - 1).size() << " ";
    for (const string& task : month.at(day - 1)) cout << task << " ";
    cout << endl;
}

void operationADD(vector<vector<string>>& month, const int& day, const string& task) {
    month.at(day - 1).push_back(task);
}

int main() {
    int numOperations, numMonth = 0, numDay = 0;
    string typeOperation, taskName, input;

    cin >> numOperations;

    vector<int> whichMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> tasksCalendar(whichMonth.at(numMonth));

    for (int i = 0; i < numOperations; i++) {

        cin >> typeOperation;

        if (typeOperation == "NEXT") {
            (numMonth > 10) ? numMonth -= 11 : numMonth++;
            tasksCalendar = operationNEXT(tasksCalendar, whichMonth.at(numMonth));
        } else if (typeOperation == "DUMP") {
            cin >> numDay;
            operationDUMP(tasksCalendar, numDay);
        } else if (typeOperation == "ADD") {
            cin >> numDay >> taskName;
            operationADD(tasksCalendar, numDay, taskName);
        } else exit(0);
    }

    return 0;
}

