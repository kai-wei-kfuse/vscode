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
        if (s1[len1 - 1] == 'S') {
            if (s2[len2 - 1] == 'S') {
                if (len2 < len1)
                    ans = 1;  //<
                else if (len1 == len2)
                    ans = 2;  //=
                else if (len1 > len2)
                    ans = 3;  //>
            } else {
                ans = 1;
            }
        } else if (s1[len1 - 1] == 'M') {
            if (s2[len2 - 1] == 'S') {
                ans = 3;
            } else if (s2[len2 - 1] == 'M') {
                ans = 2;
            } else {
                ans = 1;
            }
        } else if (s1[len1 - 1] == 'L') {
            if (s2[len2 - 1] == 'S') {
                ans = 3;
            } else if (s2[len2 - 1] == 'M') {
                ans = 3;
            } else if (s2[len2 - 1] == 'L') {
                if (len2 < len1)
                    ans = 3;
                else if (len1 == len2)
                    ans = 2;
                else if (len1 > len2)
                    ans = 1;
            }
        }
        if (ans == 1) {
            cout << "<" << endl;
        } else if (ans == 2) {
            cout << "=" << endl;
        } else if (ans == 3) {
            cout << ">" << endl;
        }
    }
}