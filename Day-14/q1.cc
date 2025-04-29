#include <bits/stdc++.h>

using namespace std;

pair<int, int> getNumbers (string line) {
    int a = 0;
    int b = 0;
    int temp = 0;

    for (char x : line) {
        if (x >= '0' && x <= '9') {
            temp = temp * 10 + (x - '0');
        }

        if (x == 'Y') {
            a = temp;
            temp = 0;
        }
    }
    b = temp;

    return {a, b};
}

int main() {
    int lineCount = 0;

    string line;
    int ax, ay, bx, by, tx, ty;

    int cost = 0;

    while (getline(cin, line)) {
        int counter = lineCount % 4;
        int temp = 0;

        pair <int, int> nums = getNumbers(line);
        cout << nums.first << " " << nums.second << endl;
        switch(counter) {
            case 0:
                ax = nums.first;
                ay = nums.second;
                break;
            case 1:
                bx = nums.first;
                by = nums.second;
                break;
            case 2: 
                tx = nums.first;
                ty = nums.second;
                break;
            default:
                break;
        }

        lineCount++;
        if (lineCount % 4 != 3) continue;

        int bPress = 100;
        int aPress = 0;
        int curx = bx * 100;
        int cyry = by * 100;

        while (tx != curx && ty != cury && aPress < 100 && bPress > 0) {
            if ((curx > tx || cury > ty) && bPress > 0) {
                curx -= bx;
                cury -= by;
                bPress--;
            }

            if ((curx < tx || cury < ty) && aPress < 100) {
                curx += ax;
                cury += ay;
                aPress++;
            }
        }

        if (curx == ty && cury == ty) {
            cost += bPress * 1 + aPress * 3;
        }
    }

    cout << cost << endl;

    return 0;
}
