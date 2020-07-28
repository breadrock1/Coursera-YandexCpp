#include "sum_reverse_sort.h"
#include "iostream"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    reverse(s.begin(), s.end());

    return s;
}

void Sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}