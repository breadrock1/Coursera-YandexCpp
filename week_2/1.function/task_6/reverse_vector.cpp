#include <iostream>
#include "vector"

using namespace std;

void Reverse(vector<int>& vec) {
    vector<int> templ = vec;

    int size = templ.size() - 1;

    for (int i = 0; i <= size; i++) vec[i] = templ[size - i];

    templ.clear();
}

int main() {
    int input;
    vector<int> numbers;

    while (cin.peek() != '\n') {
        cin >> input;
        numbers.push_back(input);
    }

    Reverse(numbers);

    return 0;
}
