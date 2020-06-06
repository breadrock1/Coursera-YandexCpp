#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input_line;
    ifstream input("input.txt");
    ofstream output("output.txt");

    while (getline(input, input_line)) {
        output << input_line << endl;
    }

    return 0;
}