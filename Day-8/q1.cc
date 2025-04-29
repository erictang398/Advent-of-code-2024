#include <bits/stdc++.h>
using namespace std;

bool checkInRange(vector<vector<int>>& board, int x, int y) {
    int rows = board.size();
    int cols = board[0].size();

    if (x < 0 || x >= cols) {
        return false;
    }

    if (y < 0 || y >= rows) {
        return false;
    }

    return true;
}

int main() {
    unordered_map<char, vector<pair<int, int>>> antennas;

    string line;

    int row = 0;
    int col = 0;

    while (getline(cin, line)) {
        int tempCol = 0;
        for(char x : line) {
            if (x == '.') {
                tempCol++;
                continue;
            }
            // form of (y,x)
            cout << row << " " << tempCol << endl;
            antennas[x].push_back({row, tempCol});
            tempCol++;
        }
        col = max(col, tempCol);
        row++;
    }

    vector<vector<int>> board(row, vector<int> (col, 0));

    for (auto x : antennas) {
        vector<pair<int, int>> antennaCoords = x.second;

        // cout << x.first << endl;

        for (int i = 0; i < antennaCoords.size(); i++) {
            int firstY = antennaCoords[i].first;
            int firstX = antennaCoords[i].second;
            for (int j = i + 1; j < antennaCoords.size(); j++) {
                int secondY = antennaCoords[j].first;
                int secondX = antennaCoords[j].second;

                int yDiff = firstY - secondY;
                int xDiff = firstX - secondX;

                // first -> second -> test point
                int firstNewTestX = secondX - xDiff;
                int firstNewTestY = secondY - yDiff;

                // cout << firstNewTestX << " " << firstNewTestY << endl;

                if (checkInRange(board, firstNewTestX, firstNewTestY)) {
                    board[firstNewTestY][firstNewTestX] = 1;
                }

                // second -> first -> test point
                int secondNewTestX = firstX + xDiff;
                int secondNewTestY = firstY + yDiff;

                if (checkInRange(board, secondNewTestX, secondNewTestY)) {
                    board[secondNewTestY][secondNewTestX] = 1;
                }
            }
        }
    }

    int sum = 0;

    for (vector<int> v : board) {
        for (int x : v) {
            sum += x;
        }
    }

    cout << sum << endl;

    return 0;
}