#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        allStrings.push_back(s);
    }

    vector<string> GetSortedStrings() {
        sort(allStrings.begin(), allStrings.end());
        return allStrings;
    }

private:
    vector<string> allStrings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) cout << s << " ";
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}