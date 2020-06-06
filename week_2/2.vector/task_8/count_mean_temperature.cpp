#include <iostream>
#include "vector"

using namespace std;

int getMeanValue(const vector<int>& vec) {
    int sum = 0;

    for (const int num : vec) sum += num;

    return sum / vec.size();
}

vector<int> countDays(vector<int>& vec) {
    vector<int> normDays;
    int minTemperature = getMeanValue(vec);

    for (int i = 0; i < vec.size(); i++)
        if (vec[i] > minTemperature) normDays.push_back(i);

    return normDays;
}

void setVectorValues(vector<int>& vec) {
    for (int& elem : vec) cin >> elem;
}

int main() {
    int size;

    cin >> size;

    vector<int> inputTempratures(size);
    setVectorValues(inputTempratures);

    inputTempratures = countDays(inputTempratures);

    cout << inputTempratures.size() << endl;
    for (int& num : inputTempratures) cout << num << " ";

    return 0;
}
