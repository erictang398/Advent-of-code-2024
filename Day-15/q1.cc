#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    
    int width = 11;
    int height = 7;

    vector<pair<int, int>> robots;

    while (getline(cin, line)) {
        stringstream ss(line);

        string token;
        int x, y, vx, vy;

        // format "p=x,y v=x,y"
        getline(ss, token, '=');
        getline(ss, token, ',');
        x = stoi(token);
        getline(ss, token, ' ');
        y = stoi(token);

        getline(ss, token, '=');
        getline(ss, token, ',');
        vx = stoi(token);
        getline(ss, token, ' ');
        vy = stoi(token);

        x = (x + vx * 100) % width;
        y = (y + vy * 100) % height;

        if (x < 0) x = width + x;
        if (y < 0) y = height + y;

        robots.push_back({x, y});
    }

    int total = 0;
    int q1, q2, q3, q4;

    for (auto p : robots) {
        int x = p.first;
        int y = p.second;

        int xHalf = width / 2;
        int yHalf = height / 2;

        // Q1  
        if (x > xHalf && y > yHalf) {
            q1++;
        }

        // Q2
        if (x < xHalf && y > yHalf) {
            q2++;
        }

        // Q3
        if (x < xHalf && y < yHalf) {
            q3++;
        }

        // Q4
        if (x > xHalf && y < yHalf) {
            q4++;
        }
    }

    total = q1 * q2 * q3 * q4;
    cout << total << endl;

    return 0;
}
