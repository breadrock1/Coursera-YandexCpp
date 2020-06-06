#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
public:
    ReversibleString() = default;

    explicit ReversibleString(const string& input) {
        str = input;
    }

    void Reverse() {
        string tmp;

        for (int i = str.size() - 1; i >= 0; --i) tmp += str[i];

        str = tmp;
        tmp.clear();
    }

    string ToString() const {
        return str;
    }

private:
    string str = "";

};


int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}