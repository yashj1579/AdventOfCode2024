
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
#include <functional>
#define prints(x) for (auto &i : x) {cout << i << " ";} cout << endl;

using namespace std;

int main() {
    vector<int> x;
    map<int, int> y;
    int N = 1000;
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob1.txt");

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        if (y.find(b) != y.end()) {
            y[b] = y[b] + 1;
        }
        else {
            y[b] = 1;
        }
    }
    int dist = 0;
    for (int i = 0; i < N; i++) {
        if (y.find(x[i]) != y.end()) {
            dist += x[i] * y.at(x[i]);
        }
    }
    cout << dist << endl;
}
