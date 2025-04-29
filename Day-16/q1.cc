#include <bits/stdc++.h>

using namespace std:

int x = 0;
int y = 0;

void tryPush(vector<vector<char>>& board, char command) {
    int temp;
    switch(command) {
        case '^':
            if (board[y-1][x] == '.') {
                board[y][x] = '.';
                y = y - 1;
                board [y][x] = '@';
                break;
            }

            temp = y;
            while (temp) {
                temp--;

                if (board[temp][x] == '#') break;

                if (board[temp][x] == '.') {
                    board[temp][x] = '0';
                    board[y][x] = '.';
                    y = y - 1;
                    board[y][x] = '@';
                    break;
                }
            }
        case '>':
            if (board[y][x + 1] == '.') {
                board[y][x] = '.';
                x = x + 1;
                board[y][x] = '@';
                break;
            }

            temp = x;
            while (temp < board[0].size() - 1) {
                temp++;

                if (board[y][temp] == '#') break;

                if (board[y][temp] = '.') {
                    board[y][temp] = '0';
                    board[y][x] = ',';
                    x = x + 1;
                    board[y][x] = '@';
                    break;
                }
            }
            break;
        case 'v':
            if (board[y + 1][x] == '.') {
                board[y][x] = '.';
                y = y + 1;
                board[y][x] = '@';
                break;
            }

            temp = y;
            while (temp < board.size() - 1) {
                temp++;

                if (board[temp][x] == '#') break;

                if (board[temp][x] == '.') {
                    board[temp][x] = '0';
                    board[y][x] = '.';
                    y = y + 1;
                    board[y][x] = '@';
                    break;
                }
            }
            break;
        case '<':
            if (board[y][x - 1] == '.') {
                board[y][x] = '.';
                x = x - 1;
                board[y][x] = '@';
                break;
            }

            temp = x;
            while (temp) {
                temp--;

                if (board[y][temp] == '#') break;

                if (board[y][temp] == '.') {
                    board[y][temp] = '0';
                    board[y][x] = '.';
                    x = x - 1;
                    board[y][x] = '@';
                    break;
                }
            }
            break;
        default:
            break;
    }
}

void printBoard(vector<vectpr<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main() {
    string line;
    
    int lineNumber = 0;

    vector<vector<char>> board;
    queue<char> commands;

    int row = 0;
    int col = 0;

    while (getline(cin, line)) {
        if (line.length() == 0) {
            break;
        }

        vector<char> temp;

        for (char c : line) {
            if (c == '@') {
                x = col;
                y = row;
            }
            col++;
            temp.push_back(c);
        }

        col = 0;
        row++;
        board.push_back(temp);
    }

    while (getline(cin, line)) {
        for (char c : line) {
            commands.push(c);
        }
    }

    while (!commands.empty()) {
        char command = commands.front();
        commands.pop();
        tryPush(board, command);
        // printBoard(board);
    }

    int sum = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '0') {
                sum += 100 * i + j;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
