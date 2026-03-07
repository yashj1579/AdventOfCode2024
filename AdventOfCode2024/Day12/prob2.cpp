
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
#define printss(x) for (auto &i : x) {for (auto &j: i) {cout << j.first << "   ";} cout << endl;}
#define db cout << "occ" << endl;
#define fors(n) for (int i = 0; i < n; i++)

using namespace std;



int main() {
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob2.txt");
    int n = 0;
    cin >> n;
    vector<vector<pair<char, bool>>> x;
    vector<vector<pair<char, bool>>> per_x;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        vector<pair<char, bool>> b;
        vector<pair<char, bool>> emp;
        vector<pair<char, bool>> per_b;
        for (auto j : a) {
            b.push_back(make_pair(j,false));
            per_b.push_back(make_pair(' ',false));
            per_b.push_back(make_pair(j,false));
            per_b.push_back(make_pair(' ',false));
            emp.push_back(make_pair(' ',false));
            emp.push_back(make_pair(' ',false));
            emp.push_back(make_pair(' ',false));
        }
        x.push_back(b);
        per_x.push_back(emp);
        per_x.push_back(per_b);
        per_x.push_back(emp);
    }


    int tot_val = 0;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            if (x[i][j].second) { //already accounted for
                continue;
            }
            x[i][j].second = true;
            vector<vector<pair<char, bool>>> new_per_x = per_x;

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

                new_per_x[3*x1+1][3*y1] = make_pair('-', false);
                new_per_x[3*x1][3*y1+1] = make_pair('-', false);
                new_per_x[3*x1+2][3*y1+1] = make_pair('-', false);
                new_per_x[3*x1+1][3*y1+2] = make_pair('-', false);

                if (x1-1 >= 0 and x[x1-1][y1].first == x[i][j].first) {
                    per -= 1;
                    new_per_x[3*x1][3*y1+1] = make_pair('!', false);
                    if (!x[x1-1][y1].second) {
                        x[x1-1][y1].second = true;
                        loc.push_back(make_pair(x1-1, y1));
                    }
                }
                if (x1+1 < x.size() and x[x1+1][y1].first == x[i][j].first) {
                    per -= 1;
                    new_per_x[3*x1+2][3*y1+1] = make_pair('!', false);
                    if (!x[x1+1][y1].second) {
                        x[x1+1][y1].second = true;
                        loc.push_back(make_pair(x1+1, y1));
                    }
                }
                if (y1-1 >= 0 and x[x1][y1-1].first == x[i][j].first) {
                    per -= 1;
                    new_per_x[3*x1+1][3*y1] = make_pair('!', false);
                    if (!x[x1][y1-1].second) {
                        x[x1][y1-1].second = true;
                        loc.push_back(make_pair(x1, y1-1));
                    }
                }
                if (y1+1 < x.size() and x[x1][y1+1].first == x[i][j].first) {
                    per -= 1;
                    new_per_x[3*x1+1][3*y1+2] = make_pair('!', false);
                    if (!x[x1][y1+1].second) {
                        x[x1][y1+1].second = true;
                        loc.push_back(make_pair(x1, y1+1));
                    }
                }
            }
            //go through perimiter list
            //printss(new_per_x)
            per = 0;
            for (int i = 0; i < new_per_x.size(); i++) {
                for (int j = 0; j < new_per_x[i].size(); j++) {
                    if (new_per_x[i][j].first == '-' and new_per_x[i][j].second == false) {
                        //we found perimiter location
                        new_per_x[i][j].second = true;
                        per += 1;
                        //disable all possible other locations
                        vector<int> xdir = {-3,0,3};
                        vector<int> ydir = {-3,0,3};
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {

                                if (xdir[k] == 0 and ydir[l] == 0) {
                                    continue;
                                }
                                if (not (xdir[k] == 0 or ydir[l] == 0)) {
                                    continue;
                                }
                                int count = 1;
                                //checks if can jump 3 in each location (valid square and "-" and unvisited)
                                //makes it visited
                                while (i+xdir[k]*count >= 0 and i+xdir[k]*count < new_per_x.size() and j+ydir[l]*count >= 0 and j+ydir[l]*count < new_per_x[i].size() and new_per_x[i+xdir[k]*count][j+ydir[l]*count ].first == '-' and
                                       !new_per_x[i + xdir[k] * count][j + ydir[l] * count].second) {
                                    new_per_x[i + xdir[k] * count][j + ydir[l] * count].second = true;
                                    new_per_x[i + xdir[k] * count][j + ydir[l] * count].first = '$';
                                    count += 1;
                                }
                            }
                        }
                    }
                }
            }
            //printss(new_per_x)
            cout << x[i][j].first << " " << area << " " << per << "\n";
            tot_val += area * per;
        }
    }
    cout << tot_val << endl;


}
