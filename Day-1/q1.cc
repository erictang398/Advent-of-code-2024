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

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int sum = 0;

    for (int i = 0; i < left.size(); i++) {
        sum += abs(left[i] - right[i]);
    }

    cout << sum << endl;
}