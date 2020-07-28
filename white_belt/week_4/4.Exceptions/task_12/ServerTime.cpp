#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>

using namespace std;

static string AskTimeServer() {
    string line;
    ifstream input("unit.txt");

    while (getline(input, line)) return line;
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
            return last_fetched_time;
        } catch (system_error&) {
            return last_fetched_time;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;

    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }

    return 0;
}