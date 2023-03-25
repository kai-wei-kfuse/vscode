#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    int g = 0, p = 0, l = 0, t = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'T') {
            t++;
        }
        if (s[i] == 'G') {
            g++;
        }
        if (s[i] == 'L') {
            l++;
        }
        if (s[i] == 'P') {
            p++;
        }
    }
    while (g || p || t || l) {
        if (g--) {
            cout << "G";
        }
        if (p--) {
            cout << "P";
        }
        if (l--) {
            cout << "L";
        }
        if (t--) {
            cout << "T";
        }
    }
}