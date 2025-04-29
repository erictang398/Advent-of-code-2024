#include <bits/stdc++.h>
using namespace std;

bool checkPossibleTarget(long long target, vector<int>& values, long long total, int pos) {
    if (pos == values.size() && total == target) {
        return true;
    } 

    if (pos == values.size() && total != target) {
        return false;
    }

    int concatPower = to_string(values[pos]).length();

    return checkPossibleTarget(target, values, total + values[pos], pos + 1) || 
    checkPossibleTarget(target, values, total * values[pos], pos + 1) || 
    checkPossibleTarget(target, values, total * (pow(10, concatPower)) + values[pos], pos + 1);
}

int main () {
    long long sum = 0;

    string line;

    while (getline(cin, line)) {
        istringstream iss(line);

        long long key;
        char colon;

        vector<int> values;

        iss >> key >> colon;

        long value;

        while (iss >> value) {
            values.push_back(value);
        }

        if (checkPossibleTarget(key, values, values[0], 1)) {
            sum += key;
        } 
    }

    cout << sum << endl;

    return 0;
}