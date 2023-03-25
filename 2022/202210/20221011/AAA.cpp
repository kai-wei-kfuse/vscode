#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int len1 = s1.length();
        int len2 = s2.length();
        int ans = 0;
        int a1 = 0, cnt = 1, a2 = 0;
        for (int i = 0; i < len1; i++) {
            if (s1[i] == 'X') {
                cnt++;
            } else if (s1[i] == 'S') {
                a1 -= cnt;
            } else if (s1[i] == 'M') {
                a1 = 0;
            } else if (s1[i] == 'L') {
                a1 += cnt;
            }
        }
        cnt = 1;
        for (int i = 0; i < len2; i++) {
            if (s2[i] == 'X') {
                cnt++;
            } else if (s2[i] == 'S') {
                a2 -= cnt;
            } else if (s2[i] == 'M') {
                a2 = 0;
            } else if (s2[i] == 'L') {
                a2 += cnt;
            }
        }
        if (a1 < a2) {
            cout << "<" << endl;
        } else if (a1 == a2) {
            cout << "=" << endl;
        } else if (a1 > a2) {
            cout << ">" << endl;
        }
    }
}