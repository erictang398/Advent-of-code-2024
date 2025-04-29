// this solution was absolutely disgusting
// logic is correct but code was terrible

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
        int fileSize = 1;
        int spaceCount = 0;

        if (storage[left] != -1) {
            left++;
            continue;
        }

        if (storage[right] == -1) {
            right--;
            continue;
        }

        while (storage[right] != -1 && storage[right] == storage[right - 1]) {
            fileSize++;
            right--;
        }

        right--;

        // cout << storage[right + 1] << endl;;

        while (left < right) {
            while (storage[left] == -1) {
                spaceCount++;
                left++;
            }

            if (fileSize <= spaceCount) {
                for (int i = left - spaceCount; i < left - spaceCount + fileSize; i++) {
                    storage[i] = storage[right + fileSize];
                }

                for (int i = right + fileSize; i > right; i--) {
                    storage[i] = -1;
                }
                left = 0;
                break;
            } else {
                spaceCount = 0;
                while (storage[left] != -1 && left < right) {
                    left++;
                }
            }
        }

        left = 0;
    }

    long long total = 0;

    for (int i = 0; i < storage.size(); i++) {
        if (storage[i] == -1) {
            continue;
        }

        total += storage[i] * i;

        // if (storage[i] == -1) {
        //     cout << ".";
        // } else {
        //     cout << storage[i];
        // }
    }

    // cout << endl;
    cout << total << endl;

    return 0;
}