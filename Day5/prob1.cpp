

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

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob1.txt");
    int n = 0;
    cin >> n;
    map<int, set<int>> y;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<string> x = split(s, "|");
        int a = stoi(x[0]);
        int b = stoi(x[1]);
        if (y.contains(b)) {
            y[b].insert(a);
        }
        else {
            y[b] = {a};
        }
    }
    //cout << "FIRST PART DONE" << endl;

    ifstream yin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob2.txt");
    yin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string s;
        yin >> s;
        if (s.empty()) {
            break;
        }
        vector<string> x = split(s, ",");
        //cout << "occ" << endl;
        vector<int> cont;
        bool ch = false;
        for (int i = 0; i < x.size(); i++) {
            set<int> check = y[stoi(x[i])];
            for (int i = 0; i < cont.size(); i++) {
                if (!check.contains(cont[i])) {
                    ch = true;
                }
            }
            cont.push_back(stoi(x[i]));
        }
        if (!ch) {
            sum += stoi(x[x.size() / 2]);
        }
    }
    cout << sum << endl;

}
