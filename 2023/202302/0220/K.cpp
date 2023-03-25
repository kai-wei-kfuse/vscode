#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s += '#';
        int len = s.size();
        int num = 0, fun = 0;
        int a = 0, b = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num++;
            } else {
                fun++;
                if ((s[i + 1] >= '0' && s[i + 1] <= '9')||s[i+1]=='#') {
                    if (num > fun + 1) {
                       // cout << num - fun - 1 << endl;
                        a += num - fun - 1;
                    } else if (num < fun + 1) {
                        //cout << fun - num + 1 << endl;
                        b += fun - num + 1;
                    }
                    num = 0, fun = 0;
                }
            }
        }
        cout << max(a, b) << endl;
    }
}