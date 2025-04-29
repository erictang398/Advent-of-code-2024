#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

// let 0 be nothing, 1 be walked, 2 be obstacle
    vector<vector<int>> board;

int checkEscape(int startX, int startY) {
    int total = board.size() * board[0].size();
    int dir = 0;

    for (int i = 0; i < total; i++) {
        int newX = startX + directions[dir % 4].first;
        int newY = startY + directions[dir % 4].second;

        if (newX < 0 || newX >= board[0].size() || newY < 0 || newY >= board.size()) {
            return 0;
        }

        if (board[newY][newX] == 2) {
            dir++;
        } else {
            startX = newX;
            startY = newY;
        }
    }
    
    return 1;
}

int main() {
    int sum = 0;

    string line;

    set<pair<int, int>> visited;

    int tempY = 0, curX = 0, curY = 0, startX = 0, startY = 0;

    while (getline(cin, line)) {
        vector<int> row;
        int tempX = 0;
        for (char x : line) {
            if (x == '.') {
                row.push_back(0);
            } else if (x == '#') {
                row.push_back(2);
            } else {
                row.push_back(0);
                startX = curX = tempX;
                startY = curY = tempY;
                visited.insert({curX, curY});
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

        if (newX < 0 || newX >= board[0].size() || newY < 0 || newY >= board.size()) {
            break;
        }

        if (board[newY][newX] == 0) {
            visited.insert({newX, newY});
            curX = newX;
            curY = newY;
        } else if (board[newY][newX] == 1) {
            curX = newX;
            curY = newY;
        } else {
            dir++;
        }
    }

    for (pair<int, int> coords : visited) {
        int x = coords.first;
        int y = coords.second;
        board[y][x] = 2;
        sum += checkEscape(startX, startY);
        board[y][x] = 0;
    }

    cout << sum << endl;

    return 0;
}