#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input_line;
    ifstream input("input.txt");

    while (getline(input, input_line)) {
        cout << input_line << endl;
    }

    return 0;
}