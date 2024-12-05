#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> left;
    vector<int> right;

    int x, y;
    while (cin >> x >> y) {
        left.push_back(x);
        right.push_back(y);
    }

    unordered_map<int, int> rightNums;

    for (int x : right) {
        rightNums[x] += 1;
    }

    int sum = 0;

    for (int x : left) {
        sum += rightNums[x] * x;
    }

    cout << sum << endl;
}