#include <bits/stdc++.h>
using namespace std;

bool isSafeReport(vector<int>& report) {
    if (report.size() == 1) return true;

    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 1; i < report.size(); i++) {
        if (abs(report[i] - report[i - 1]) > 3 || abs(report[i] - report[i - 1]) < 1) {
            return false;
        }

        if (report[i] > report[i - 1]) {
            isDecreasing = false;
        } else {
            isIncreasing = false;
        }
    }

    return isIncreasing || isDecreasing;
}

int main() {
    string line;
    int safeReports = 0;

    while(getline(cin, line)) {
        stringstream ss(line);
        vector<int> report;
        int x;

        while(ss >> x) {
            report.push_back(x);
        }

        if (isSafeReport(report)) {
            safeReports++;
            continue;
        } 

        for (int i = 0; i < report.size(); i++) {
            vector<int> modifiedReport;
            for (int j = 0; j < report.size(); j++) {
                if (j == i) continue;

                modifiedReport.push_back(report[j]);
            }

            if (isSafeReport(modifiedReport)) {
                safeReports++;
                break;
            }
        }
    }

    cout << safeReports << endl;
}
