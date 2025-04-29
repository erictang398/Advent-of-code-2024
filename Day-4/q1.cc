#include <bits/stdc++.h>
using namespace std;

int checkXMAS(vector<vector<char>>& board, int i, int j) {
    int width = board[0].size();
    int height = board.size();
    string target = "XMAS";
    int count = 0;

    vector<pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}
    };

    for (auto [rowOffset, colOffset] : directions) {
        bool match = true;

        for (int k = 0; k < target.size(); k++) {
            int newRow = j + k * rowOffset;
            int newCol = i + k * colOffset;

            if (newRow < 0 || newRow >= height || newCol < 0 || newCol >= width) {
                match = false;
                break;
            }

            if (board[newRow][newCol] != target[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            count++;
        }
    }

    return count;
}

int main() {
    int total = 0;

    string line;
    vector<vector<char>> board;

    while (getline(cin, line)) {
        vector<char> temp;
        for (char x : line) {
            temp.push_back(x);
        }
        board.push_back(temp);
    }

    int height = board.size();
    int width = board[0].size();

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (board[j][i] == 'X') {
                total += checkXMAS(board, i, j);
            }
        }
    }

    cout << total << endl;
    return 0;
}
