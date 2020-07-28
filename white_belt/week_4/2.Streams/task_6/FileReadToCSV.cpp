#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int x, y;
    string lines;

    ifstream input("input.txt");

    input >> x;
    input.ignore(1);
    input >> y;
    input.ignore(1);

    for (int i = x; i > 0;--i) {
        for (int z = y; z > 1; --z) {
            getline(input, lines, ',');
            cout << setw(10) << lines << " ";
        }
        getline(input, lines);
        cout << setw(10) << lines << endl;
    }

    return 0;
}
