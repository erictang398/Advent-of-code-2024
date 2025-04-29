#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<vector<char>> board;
    string line;

    while (getline(cin, line)) {
        vector<char> row;
        for (char x : line) {
            row.push_back(x);
        }
        board.push_back(row);
    }

    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (visited[i][j]) {
                continue;
            }

            int cost = 
        }
    }

    std::cout << nums.size() << std::endl;

    return 0;
} 
