#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string studentName, studentSurname, studentBirthday;
};

void getStudentName(const vector<Student>& students, const int& index) {
    cout << students[index - 1].studentName << " " << students[index - 1].studentSurname;
}

void getStudentBirthday(const vector<Student>& students, const int& index) {
    cout << students[index - 1].studentBirthday;
}

int main() {
    int numRequests, day, month, year, numStudent;
    string name, surname, birthday, typeOperation;
    vector<Student> allStudents;

    cin >> numRequests;

    if (numRequests < 0 || numRequests > 10000)  exit(0);

    for (int i = 0; i < numRequests; ++i) {
        cin >> name >> surname >> day >> month >> year;

        if ((name.length() < 1 || name.length() > 15) ||
            (surname.length() < 1 || surname.length() > 15) || (day < 0 || day > 1000000000) ||
            (month < 0 || month > 1000000000) || (year < 0 || year > 1000000000))
        {
            continue;
        }

        birthday = to_string(day) + "." + to_string(month) + "." + to_string(year);
        allStudents.push_back({ name, surname, birthday });
    }

    cin >> numRequests;

    if (numRequests < 0 || numRequests > 10000) exit(0);

    for (int i = 0; i < numRequests; ++i) {
        cin >> typeOperation >> numStudent;

        if ((typeOperation.length() <= 0 || typeOperation.length() > 15) ||
            (numStudent <= 0 || numStudent > 1000000000))
        {
            cout << "bad request" << endl;
            continue;
        }

        if (allStudents.size() < numStudent) cout << "bad request";
        else if (typeOperation == "name") getStudentName(allStudents, numStudent);
        else if (typeOperation == "date") getStudentBirthday(allStudents, numStudent);
        else cout << "bad request";

        cout << endl;
    }

    return 0;
}
