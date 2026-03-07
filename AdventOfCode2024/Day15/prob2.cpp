

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
//checks if vector can move
bool can_move(vector<vector<char>> &x, int xpos, int ypos, int xdir, int ydir, char store) {
    //cout << xpos << " + " << xdir << ", " << ypos << " + " << ydir << endl;
    if (x[xpos + xdir][ypos + ydir] == '.') {
        x[xpos+xdir][ypos+ydir] = store;
        return true;
    }
    else if (x[xpos + xdir][ypos + ydir] == '#') {
        return false;
    }
    else if (xdir != 0) {
        //physics for up/down
        if (x[xpos + xdir][ypos + ydir] == '[') {
            char store1 = x[xpos + xdir][ypos + ydir];
            char store2 = x[xpos + xdir][ypos + ydir + 1];
            x[xpos + xdir][ypos + ydir] = store;
            x[xpos + xdir][ypos + ydir + 1] = '.';
            return can_move(x, xpos + xdir, ypos + ydir, xdir, ydir, store1) and
                   can_move(x, xpos + xdir, ypos + ydir + 1, xdir, ydir, store2);
        } else if (x[xpos + xdir][ypos + ydir] == ']') {
            char store1 = x[xpos + xdir][ypos + ydir];
            char store2 = x[xpos + xdir][ypos + ydir - 1];
            x[xpos + xdir][ypos + ydir] = store;
            x[xpos + xdir][ypos + ydir - 1] = '.';
            return can_move(x, xpos + xdir, ypos + ydir, xdir, ydir, store1) and
                   can_move(x, xpos + xdir, ypos + ydir - 1, xdir, ydir, store2);
        }
    }
    else if (ydir != 0) {
        //physics for left/right
        if (x[xpos + xdir][ypos + ydir] == '[') { //we are going right
            //change the stuff
            char store2 = x[xpos + xdir][ypos + ydir * 2];
            x[xpos + xdir][ypos + ydir] = store;
            x[xpos + xdir][ypos + ydir * 2] = '[';
            return can_move(x, xpos+xdir, ypos+ydir*2, xdir, ydir, store2);
        }
        else if (x[xpos + xdir][ypos + ydir] == ']') { //we are going left
            //change the stuff
            char store2 = x[xpos + xdir][ypos + ydir * 2];
            x[xpos + xdir][ypos + ydir] = store;
            x[xpos + xdir][ypos + ydir * 2] = ']';
            //printss(x)
            return can_move(x, xpos+xdir, ypos+ydir*2, xdir, ydir, store2);
        }
    }
    cout << "weird" << endl;
    return false;
}
//changes the vector


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
            if (a[j] == '@') {
                x[i].push_back(a[j]);
                x[i].push_back('.');
                pos = make_pair(i, j*2);
            }
            else if (a[j] == 'O') {
                x[i].push_back('[');
                x[i].push_back(']');
            }
            else {
                x[i].push_back(a[j]);
                x[i].push_back(a[j]);
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
        //cout << i << " " << pos.first << " " << pos.second << endl;
        vector<vector<char>> copy = x;
        bool worked = can_move(copy,pos.first, pos.second, xdir, ydir, '@');
        if (worked) { //if it isnt out of bounds
            x[pos.first][pos.second] = '.';
            worked = can_move(x,pos.first, pos.second, xdir, ydir, '@');
            pos.first += xdir;
            pos.second += ydir;

        }
    }
    printss(x)
    int count = 0;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            if (x[i][j] == '[') {
                count += i * 100 + j;
            }
        }
    }
    cout << count << endl;
}
