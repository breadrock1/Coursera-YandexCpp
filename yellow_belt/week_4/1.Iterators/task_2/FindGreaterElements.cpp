#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> sorted;

    auto it = find_if(elements.begin(), elements.end(), [border](const T& t) {
        return t >= border;
    });

    for (it; it != elements.end(); ++it) {
        if (*it == border) continue;
        sorted.push_back(*it);
    }

    return sorted;
}

int main() {

    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : FindGreaterElements(set<int>{1, 4, 6, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;

    return 0;
}