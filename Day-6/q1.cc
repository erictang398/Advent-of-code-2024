#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 1;

    vector<pair<int, int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    string line;

    // let 0 be nothing, 1 be walked, 2 be obstacle
    vector<vector<int>> board;

    int tempY = 0, curX = 0, curY = 0;

    while (getline(cin, line)) {
        vector<int> row;
        int tempX = 0;
        for (char x : line) {
            if (x == '.') {
                row.push_back(0);
            } else if (x == '#') {
                row.push_back(2);
            } else {
                row.push_back(1);
                curX = tempX;
                curY = tempY;
            }
            tempX++;
        }
        tempY++;
        board.push_back(row);
    }

    int total = board.size() * board[0].size();
    int dir = 0;

    for (int i = 0; i < total; i++) {
        int newX = curX + directions[dir % 4].first;
        int newY = curY + directions[dir % 4].second;
        // cout << directions[dir % 4].first << " " << directions[dir % 4].second << endl;
        if (newX < 0 || newX >= board[0].size() || newY < 0 || newY >= board.size()) {
            break;
        }

        if (board[newY][newX] == 0) {
            curX = newX;
            curY = newY;
            board[newY][newX] = 1;
            sum++;
        } else if (board[newY][newX] == 1) {
            curX = newX;
            curY = newY;
        } else {
            dir++;
        }
    }

    cout << sum << endl;

    return 0;
}