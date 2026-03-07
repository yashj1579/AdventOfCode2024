

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
#define printss(x) for (auto &i : x) {for (auto &j: i) {cout << j << " ";} cout << endl;}
#define fors(n) for (int i = 0; i < n; i++)

using namespace std;

vector<pair<int, int>> loc(int x1, int y1, int x2, int y2, int xmax, int ymax) {
    vector<pair<int, int>> res;
    int distx = abs(x1 - x2);
    int disty = abs(y1 - y2);
    vector<int> newx1, newx2, newy1, newy2;
    if (x1 < x2) {
        while (x1 >= 0) {
            newx1.push_back(x1);
            x1 -= distx;
        }
        while (x2 < xmax) {
            newx2.push_back(x2);
            x2 += distx;
        }
    }
    else {
        while (x2 >= 0) {
            newx2.push_back(x2);
            x2 -= distx;
        }
        while (x1 < xmax) {
            newx1.push_back(x1);
            x1 += distx;
        }
    }
    if (y1 < y2) {
        while (y1 >= 0) {
            newy1.push_back(y1);
            y1 -= disty;
        }
        while (y2 < ymax) {
            newy2.push_back(y2);
            y2 += disty;
        }
    }
    else {
        while (y2 >= 0) {
            newy2.push_back(y2);
            y2 -= disty;
        }
        while (y1 < ymax) {
            newy1.push_back(y1);
            y1 += disty;
        }
    }
    int pos = 0;
    while (pos < newx1.size() and pos < newy1.size()) {
        res.push_back(make_pair(newx1[pos], newy1[pos]));
        pos += 1;
    }
    pos = 0;
    while (pos < newx2.size() and pos < newy2.size()) {
        res.push_back(make_pair(newx2[pos], newy2[pos]));
        pos += 1;
    }
    return res;
}

int main() {
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob1.txt");
    int n = 0;
    cin >> n;
    vector<string> x;
    vector<string> rep;
    fors(n) {
        string a;
        cin >> a;
        x.push_back(a);
        rep.push_back(a);
    }
    map<char, vector<pair<int, int>>> y;
    int sum = 0;
    fors(n) {
        for (int j = 0; j < x[i].size(); j++) {
            if (x[i][j] != '.' and x[i][j] != '#') {
                if (y.contains(x[i][j])) {
                    auto z = y[x[i][j]];
                    for (auto k : z) {
                        auto as = loc(i, j, k.first, k.second, x.size(), x[i].size());
                        for (int l = 0; l < as.size(); l++) {
                            if (rep[as[l].first][as[l].second] != '#') {
                                rep[as[l].first][as[l].second] = '#';
                                sum += 1;
                            }
                        }
                    }
                    y[x[i][j]].push_back(make_pair(i, j));
                }
                else {
                    y[x[i][j]] = {make_pair(i,j)};
                }
            }
        }
    }
    printss(rep)
    cout << sum << endl;


}
