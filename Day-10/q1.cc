#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

int backtrack(vector<vector<int>>& board, vector<vector<int>>& visited, int x, int y, int cur) {
    if (x < 0 || x >= board[0].size()) return 0;
    if (y < 0 || y >= board.size()) return 0;

    if (visited[y][x]) return 0;

    if (board[y][x] != cur) return 0;

    if (cur == 0 && visited[y][x] == 0) {
        visited[y][x] = 1;
        return 1;
    }
    
    if (cur == 0) {
        return 0;
    }

    visited[y][x] = 1;

    int sum = 0;

    for (auto dir : directions) {
        int dirX = dir.first;
        int dirY = dir.second;
        sum += backtrack(board, visited, x + dirX, y + dirY, cur - 1);
    }

    return sum;
}

int main() {
    string line;

    vector<vector<int>> board;

    while (getline(cin, line)) {
        vector<int> temp;

        for (char n : line) {
            temp.push_back(n - '0');
        }

        board.push_back(temp);
    }

    int sum = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 9) {
                vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

                sum += backtrack(board, visited, j, i, 9);
            }
        }
    }

    cout << sum << endl;

    return 0;
}