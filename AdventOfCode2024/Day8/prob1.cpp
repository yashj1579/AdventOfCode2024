

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

vector<pair<int, int>> loc(int x1, int y1, int x2, int y2) {
    vector<pair<int, int>> res;
    int distx = abs(x1 - x2);
    int disty = abs(y1 - y2);
    int newx1, newx2, newy1, newy2;
    if (x1 < x2) {
        newx1 = x1 - distx;
        newx2 = x2 + distx;
    }
    else {
        newx1 = x1 + distx;
        newx2 = x2 - distx;
    }
    if (y1 < y2) {
        newy1 = y1 - disty;
        newy2 = y2 + disty;
    }
    else {
        newy1 = y1 + disty;
        newy2 = y2 - disty;
    }
    res.push_back(make_pair(newx1, newy1));
    res.push_back(make_pair(newx2, newy2));
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
                        auto as = loc(i, j, k.first, k.second);
                        if (as[0].first < x.size() and as[0].first >= 0 and as[0].second < x[i].size() and as[0].second >= 0) {
                            if (rep[as[0].first][as[0].second] != '#') {
                                rep[as[0].first][as[0].second] = '#';
                                sum += 1;
                            }

                        }
                        if (as[1].first < x.size() and as[1].first >= 0 and as[1].second < x[i].size() and as[1].second >= 0) {
                            if (rep[as[1].first][as[1].second] != '#') {
                                rep[as[1].first][as[1].second] = '#';
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
