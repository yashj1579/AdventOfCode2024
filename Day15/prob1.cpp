

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
#define printss(x) for (auto &i : x) {for (auto &j: i) {cout << j << "   ";} cout << endl;}

#define fors(n) for (int i = 0; i < n; i++)

using namespace std;
bool bounds(pair<int, int> pos, vector<vector<char>> mat) {
    if (pos.first < 0 or pos.first >= mat.size() or pos.second < 0 or pos.second >= mat[0].size()) {
        return false;
    }
    return true;
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
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob2.txt");
    int n = 0;
    cin >> n;
    vector<vector<char>> x(n);
    pair<int, int> pos;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < a.size(); j++) {
            x[i].push_back(a[j]);
            if (a[j] == '@') {
                pos = make_pair(i, j);
            }
        }
    }
    printss(x)
    string walk;
    ifstream yin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob3.txt");
    yin >> n;
    fors(n) {
        string a;
        yin >> a;
        walk += a;
    }

    cout << walk << endl;
    for (auto i : walk) {
        int xdir = i=='^' ? -1 : i=='v';
        int ydir = i=='<' ? -1 : i=='>';
        cout << i << " " << pos.first << " " << pos.second << endl;
        int am = 0;
        bool worked = true;
        try {
            while (x[pos.first + xdir * am][pos.second + ydir * am] != '.') {
                if (x[pos.first + xdir * am][pos.second + ydir * am] == '#') {
                    throw 505;
                }
                am += 1;
            }
        }
        catch (...) { //it goes out of bounds
            cout << "occ" << endl;
            worked = false;
        }
        if (worked) { //if it isnt out of bounds
            am = 1;
            x[pos.first][pos.second] = '.';
            char store = '@';
            while (x[pos.first + xdir * am][pos.second + ydir * am] != '.') { //move everything down
                //switch
                char hold = x[pos.first + xdir * am][pos.second + ydir * am];
                x[pos.first + xdir * am][pos.second + ydir * am] = store;
                store = hold;
                am += 1;
            }
            x[pos.first + xdir * am][pos.second + ydir * am] = store;
            pos.first += xdir;
            pos.second += ydir;
        }
    }
    printss(x)
    int count = 0;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            if (x[i][j] == 'O') {
                count += i * 100 + j;
            }
        }
    }
    cout << count << endl;
}
