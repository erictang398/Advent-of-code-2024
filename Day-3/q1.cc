#include <bits/stdc++.h>
using namespace std;

int processInput(string line) {
    int total = 0;
    int i = 0;

    while (i < line.size()) {
        if (line.substr(i, 4) == "mul(") {
            i += 4;
            int num1 = 0;
            int num2 = 0;

            while (i < line.size() && isdigit(line[i]) && num1 < 1000) {
                num1 = num1 * 10 + (line[i] - '0');
                i++;
            }

            if (line[i] != ',') {
                continue;
            }

            i++;

            while (i < line.size() && isdigit(line[i]) && num2 < 1000) {
                num2 = num2 * 10 + (line[i] - '0');
                i++;
            }

            if (line[i] != ')') {
                continue;
            }

            i++;

            total += num1 * num2;
        } else {
            i++;
        }
    }

    return total;
}

int main() {
    int total = 0;
    string line;

    while(getline(cin, line)) {
        total += processInput(line);
    }

    cout << total << endl;
}
