

//Starting Code
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <regex>
#include <functional>
#define prints(x) for (auto &i : x) {cout << i << " ";} cout << endl;

using namespace std;

bool bounds(pair<int, int> pos, vector<vector<char>> mat) {
    if (pos.first < 0 or pos.first >= mat.size() or pos.second < 0 or pos.second >= mat[0].size()) {
        return false;
    }
    return true;
}

pair<int, int> adder(pair<int, int> pos, int xdir, int ydir) {
    return make_pair(pos.first + xdir, pos.second + ydir);
}

void print(vector<vector<char>> x) {
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); ++j) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob1.txt");
    int n = 0;
    cin >> n;
    vector<vector<char>> x(n);
    pair<int, int> pos;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < a.size(); j++) {
            x[i].push_back(a[j]);
            if (a[j] == '^') {
                pos = make_pair(i, j);
            }
        }
    }
    int xdir = -1;
    int ydir = 0;
    while (bounds(adder(pos, xdir, ydir), x)) {
        x[pos.first][pos.second] = 'X';
        if (x[adder(pos, xdir, ydir).first][adder(pos, xdir, ydir).second] == '#') {
            int hold = xdir;
            xdir = ydir;
            ydir = -1 * hold;
        }
        else {
            pos = adder(pos, xdir, ydir);
        }
        x[pos.first][pos.second] = '^';
    }
    //print(x);
    int counter = 0;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            if (x[i][j] == 'X') {
                counter += 1;
            }
            if (x[i][j] == '^') {
                counter += 1;
            }
        }
    }

    cout << counter;

}
