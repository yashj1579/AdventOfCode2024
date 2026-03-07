

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
#define printss(x) for (auto &i : x) {for (auto &j: i) {cout << j.first << "-" << j.second.size() << "   ";} cout << endl;}

#define fors(n) for (int i = 0; i < n; i++)

using namespace std;



int main() {
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob2.txt");
    int n = 0;
    cin >> n;
    vector<vector<pair<char, bool>>> x;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        vector<pair<char, bool>> b;
        for (auto j : a) {
             b.push_back(make_pair(j,false));
        }
        x.push_back(b);
    }
    //int tot_area = 0;
    //int tot_per = 0;
    int tot_val = 0;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            if (x[i][j].second) { //already accounted for
                continue;
            }
            x[i][j].second = true;
            int area = 0;
            int per = 0;
            vector<pair<int, int>> loc;
            loc.push_back(make_pair(i,j));
            while (!loc.empty()) {
                int x1 = loc[0].first;
                int y1 = loc[0].second;
                loc.erase(loc.begin());
                area += 1;
                per += 4;
                if (x1-1 >= 0 and x[x1-1][y1].first == x[i][j].first) {
                    per -= 1;
                    if (!x[x1-1][y1].second) {
                        x[x1-1][y1].second = true;
                        loc.push_back(make_pair(x1-1, y1));
                    }
                }
                if (x1+1 < x.size() and x[x1+1][y1].first == x[i][j].first) {
                    per -= 1;
                    if (!x[x1+1][y1].second) {
                        x[x1+1][y1].second = true;
                        loc.push_back(make_pair(x1+1, y1));
                    }
                }
                if (y1-1 >= 0 and x[x1][y1-1].first == x[i][j].first) {
                    per -= 1;
                    if (!x[x1][y1-1].second) {
                        x[x1][y1-1].second = true;
                        loc.push_back(make_pair(x1, y1-1));
                    }
                }
                if (y1+1 < x.size() and x[x1][y1+1].first == x[i][j].first) {
                    per -= 1;
                    if (!x[x1][y1+1].second) {
                        x[x1][y1+1].second = true;
                        loc.push_back(make_pair(x1, y1+1));
                    }
                }
            }
            cout << x[i][j].first << " " << area << " " << per << "\n";
            tot_val += area * per;
        }
    }
    cout << tot_val << endl;


}
