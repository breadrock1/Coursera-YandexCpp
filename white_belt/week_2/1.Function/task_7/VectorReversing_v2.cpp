#include <iostream>
#include "vector"

using namespace std;

vector<int> Reversed(const vector<int>& vec) {
    int size = vec.size() - 1;
    vector<int> templ = vec;

    for (int i = size; i >= 0; i--) {
        templ[i] = vec[size - i];
    }

    return templ;
}

int main() {
    int input;
    vector<int> numbers;

    while (cin.peek() != '\n') {
        cin >> input;
        numbers.push_back(input);
    }

    numbers = Reversed(numbers);

    return 0;
}
