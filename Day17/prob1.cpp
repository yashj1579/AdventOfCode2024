
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
int A = 0;
int B = 0;
int C = 0;
vector<string> code;
int pos = 0;
int combo(int x) {
    if (x == 4)return A;
    if (x == 5)return B;
    if (x == 6)return C;
    if (x == 7) {
        cout << ("error");
        return 0;
    }
    return x;
}

void instruct(int opcode, int operand) {
    pos += 2;
    if (opcode == 0) {
        A = int(A / pow(2, combo(operand)));
        return;
    }
    if (opcode == 1) {
        B = B ^ operand;
        return;
    }
    if (opcode == 2) {
        B = combo(operand) % 8;
        return;
    }
    if (opcode == 3) {
        if (A == 0) {
            return;
        }
        pos = operand;
    }
    if (opcode == 4) {
        B = B ^ C;
    }
    if (opcode == 5) {
        cout << combo(operand) % 8 << ",";
    }
    if (opcode == 6) {
        B = int(A / pow(2, combo(operand)));
        return;
    }
    if (opcode == 7) {
        C = int(A / pow(2, combo(operand)));
        return;
    }
}

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
    //getting input
    ifstream cin ("/Users/yashjain/Desktop/Programming/CPPLabs/AdventOfCode/prob2.txt");
    string s;
    getline(cin, s);
    A = stoi(s.substr(12));
    getline(cin, s);
    B = stoi(s.substr(12));
    getline(cin, s);
    C = stoi(s.substr(12));
    getline(cin, s);
    getline(cin, s);
    code = split(s.substr(9), ",");
    cout << A << " " << B << " " << C << " " << endl;
    prints(code)
    //performing output
    while (pos < code.size()) {
        instruct(stoi(code[pos]), stoi(code[pos+1]));
    }
    cout << "\b" << endl;
}
