#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using namespace std;

template <typename T>
T Sqr(T x);

template <typename T>
vector<T> Sqr(vector<T> &v);

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> &p);

template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> &m);


template <typename T>
T Sqr(T x) {
    return x * x;
}

template <typename T>
vector<T> Sqr(vector<T> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        v.at(i) = Sqr(v.at(i));
    }

    return v;
}

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> &p) {
    p.first = Sqr(p.first);
    p.second = Sqr(p.second);

    return p;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> &m) {
    for (auto &elem : m) elem.second = Sqr(elem.second);

    return m;
}

int main() {
    vector<int> v = {1, 2, 3};

    cout << "vector:";
    for (int x : Sqr(v)) cout << ' ' << x;
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs))
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;

    map<int, pair<int, pair<int, int>>> test = {
            {1, {2, {3, 4}}},
            {1, {2, {5, 6}}}
    };

    return 0;
}