#include <bits/stdc++.h>
using namespace std;

int main() {
    char c1;
    char c2;

    vector<int> storage;

    int counter = 0;

    while (cin.get(c1)) {
        for (int i = 0; i < c1 - '0'; i++) {
            storage.push_back(counter);
        }
        counter++;
        if (cin.get(c2)) {
            for (int i = 0; i < c2 - '0'; i++) {
                storage.push_back(-1);
            }
        }
    }

    int left = 0;
    int right = storage.size() - 1;

    while (left < right) {
        if (storage[left] != -1) {
            left++;
            continue;
        }

        if (storage[right] == -1) {
            right--;
            continue;
        }

        storage[left] = storage[right];
        storage[right] = -1;
        left++;
        right--;
    }

    long long total = 0;

    for (int i = 0; i < storage.size(); i++) {
        if (storage[i] == -1) break;

        total += storage[i] * i;
        // cout << storage[i];
    }

    // cout << endl;

    cout << total << endl;

    return 0;
}