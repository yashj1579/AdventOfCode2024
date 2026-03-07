

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

set<pair<int, int>> dfs(vector<vector<pair<int, set<pair<int, int>>>>> &x, int xpos, int ypos) {
    if (x[xpos][ypos].second.size() >= 1) {
        return x[xpos][ypos].second;
    }
    //try to go four directions

    x[xpos][ypos].second.insert(make_pair(-1,-1));
    if (xpos + 1 < x.size() and x[xpos + 1][ypos].first == x[xpos][ypos].first + 1) {
        auto xs = dfs(x, xpos+1, ypos);
        for (auto i: xs) {
            x[xpos][ypos].second.insert(i);
        }
    }
    if (xpos - 1 >= 0 and x[xpos - 1][ypos].first == x[xpos][ypos].first + 1) {
        auto xs = dfs(x, xpos-1, ypos);
        for (auto i: xs) {
            x[xpos][ypos].second.insert(i);
        }
    }
    if (ypos + 1 < x[xpos].size() and x[xpos][ypos + 1].first == x[xpos][ypos].first + 1) {
        auto xs = dfs(x, xpos, ypos+1);
        for (auto i: xs) {
            x[xpos][ypos].second.insert(i);
        }
    }
    if (ypos - 1 >= 0  and x[xpos][ypos - 1].first == x[xpos][ypos].first + 1) {
        auto xs = dfs(x, xpos, ypos-1);
        for (auto i: xs) {
            x[xpos][ypos].second.insert(i);
        }
    }
    //says the node is traversed and didn't find anything

    return x[xpos][ypos].second;
}

int main() {
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob2.txt");
    int n = 0;
    int m = 42; //fill in later
    cin >> n;
    vector<vector<pair<int, set<pair<int, int>>>>> x(n, vector<pair<int, set<pair<int, int>>>>(m));
    vector<pair<int, int>> zeros;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < m; j++) {
            if (a[j] == '.') {
                x[i][j] = make_pair(-1, set<pair<int,int>>());
                continue;
            }
            if (a[j] == '0') {
                zeros.push_back(make_pair(i, j));
            }
            if (a[j] == '9') {
                pair<int, int> pos = make_pair(i, j);
                set<pair<int,int>> xs;
                xs.insert(pos);
                x[i][j] = make_pair(int(a[j])-48, set<pair<int,int>>(xs));
            }
            else {
                x[i][j] = make_pair(int(a[j])-48, set<pair<int,int>>());
            }

        }
    }

    int sum = 0;
    for (int i = 0; i < zeros.size(); i++) {
        //dfs traversal
        sum += dfs(x, zeros[i].first, zeros[i].second).size() - 1;
    }
    //printss(x);

    cout << sum << endl;


}
