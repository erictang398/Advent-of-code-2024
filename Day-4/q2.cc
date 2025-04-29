#include <bits/stdc++.h>
using namespace std;

int checkXMAS(vector<vector<char>>& board, int i, int j) {
    int width = board[0].size();
    int height = board.size();
    string target = "XMAS";
    int count = 0;

    if (i - 1 < 0 || j - 1 < 0 || i + 1 >= width || j + 1 >= height) {
        return 0;
    }

    // top left to bottom right
    if (board[j + 1][i - 1] == 'M' && board[j - 1][i + 1] == 'S') {
        count += 1;
    }

    // top right to bottom left
    if (board[j - 1][i + 1] == 'M' && board[j + 1][i - 1] == 'S') {
        count += 1;
    }

    // bottom left to top right
    if (board[j - 1][i - 1] == 'M' && board[j + 1][i + 1] == 'S') {
        count += 1;
    }

    // bottom right to top left
    if (board[j + 1][i + 1] == 'M' && board[j - 1][i - 1] == 'S') {
        count += 1;
    }
    
    return count == 2 ? 1 : 0;
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
            if (board[j][i] == 'A') {
                total += checkXMAS(board, i, j);
            }
        }
    }

    cout << total << endl;
    return 0;
}
