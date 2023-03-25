#include <bits/stdc++.h>
using namespace std;
struct xx {
    int q, w, e;
};
map<char, xx> mp;
int main() {
    mp['Y'] = {3, 0, 0};
    mp['V'] = {2, 1, 0};
    mp['G'] = {2, 0, 1};
    mp['C'] = {0, 3, 0};
    mp['X'] = {1, 2, 0};
    mp['Z'] = {0, 2, 1};
    mp['T'] = {0, 0, 3};
    mp['F'] = {1, 0, 2};
    mp['D'] = {0, 1, 2};
    mp['B'] = {1, 1, 1};
    string s;
    cin >> s;
    xx now = {0, 0, 0};
    int len = s.length();
    int q = 0, w = 0, e = 0, res = 0;
    for (int i = 0; i < len; i++) {
       
    }
    cout << len * 3 - res + len;
}
