#include <iostream>
#include "vector"

using namespace std;

int getMeanValue(const vector<int32_t>& vec) {
    int64_t sum = 0;
    int32_t size = vec.size();

    for (const int32_t& num : vec) sum += num;

    return sum / size;
}

vector<int32_t> searchDays(vector<int32_t>& vec) {
    vector<int32_t> normDays;
    int32_t minTemperature = getMeanValue(vec);

    for (int32_t i = 0; i < vec.size(); i++)
        if (vec[i] > minTemperature) normDays.push_back(i);

    return normDays;
}

int main() {
    int32_t numTemperatures;
    int32_t input;
    vector<int32_t> Temperatures;

    cin >> numTemperatures;

    for (int i = 0; i < numTemperatures; ++i) {
        cin >> input;
        Temperatures.push_back(input);
    }

    Temperatures = searchDays(Temperatures);

    cout << Temperatures.size() << endl;
    for (const int32_t& num : Temperatures) cout << num << " ";

    return 0;
}
