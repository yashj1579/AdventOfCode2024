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
    vector<int> x, y;
    int N = 1000;
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob1.txt");

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);

    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int dist = 0;
    for (int i = 0; i < N; i++) {
        dist += abs(x[i] - y[i]);
    }
    cout << dist << endl;
}
