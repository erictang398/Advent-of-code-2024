// 1. construct a mapping for the pages
// 2. create a counter for the number of in neighbors
// 3. construct the topological order using the in-degree counts
// 4. check the pages to ensure that it is indeed in topological order

#include <bits/stdc++.h>
using namespace std;

// initialize a queue
// while a queue is not empty, keep doing topological sorting
// check if the vector follows the topological array
// if it follows through, return the vector index at the middle
// otherwise, return 0

void topologicalSort(int x, vector<int>& corrected, unordered_map<int, int>& indegree, unordered_map<int, vector<int>>& map, set<int>& present) {
    corrected.push_back(x);
    for (int y : map[x]) {
        if (present.count(y)) {
            indegree[y]--;
            if (indegree[y] == 0) {
                topologicalSort(y, corrected, indegree, map, present);
            }
        }
    }
}

int main() {
    string line;
    int sum = 0;

    unordered_map<int, vector<int>> map;
    
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        int delim = line.find('|');
        int firstNumber = stoi(line.substr(0, delim));
        int secondNumber = stoi(line.substr(delim + 1));

        map[firstNumber].push_back(secondNumber);
    }

    while (getline(cin, line)) {
        vector<int> pages;

        stringstream ss(line);
        string number;

        while(getline(ss, number, ',')) {
            pages.push_back(stoi(number));
        }

        set<int> history;

        bool badOrder = false;

        unordered_map<int, int> indegree;
        set<int> present;

        for (int x : pages) {
            present.insert(x);
        }

        for (int i = 0; i < pages.size(); i++) {
            int num = pages[i];
            for (int x : map[num]) {
                if (present.count(x)) {
                    indegree[x]++;
                }
                if (history.count(x)) {
                    badOrder = true;
                }
            }
            history.insert(num);
        }

        if (badOrder) {
            vector<int> corrected;
            vector<int> starting;

            for (int x : pages) {
                if (indegree[x] == 0) {
                    starting.push_back(x);
                }
            }

            for (int x : starting) {
                topologicalSort(x, corrected, indegree, map, present);
            }

            sum += corrected[corrected.size() / 2];
        }
    }

    cout << sum << endl;

    return 0;
}
