#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string input_line;

    ifstream input("input.txt");

    while (getline(input, input_line)) {
        float input_num = atof(input_line.c_str());

        cout << fixed << setprecision(3);
        cout << input_num << endl;
    }

    return 0;
}
