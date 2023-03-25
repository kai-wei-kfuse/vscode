#include <bits/stdc++.h>
using namespace std;
int main() {
    int v1, v2, tt, s, l;
    cin >> v1 >> v2 >> tt >> s >> l;
    int ans = 0;
    if (v2 > v1) {
        cout << "T" << endl;
        ans = l / v2;
        if (l % v2 != 0)
            ans++;
        cout << ans ;
    } else if (v1 == v2) {
        cout << "D" << endl;
        ans = l / v2;
        if (l % v2 != 0)
            ans++;
        cout << ans ;
    } else {
        int t = 0, m1 = 0, m2 = 0;
        int flag = 0;
        while (m1 < l && m2 < l) {
            if (flag == 0) {
                m1 += v1;
            }
            if (flag>0) {
                flag--;
            }
            m2 += v2;
            if (m1 - m2 >= tt) {
                flag = s;
            }
            t++;
        }
        if (m1 >= l && m2 >= l) {
            cout << "D" << endl;
        } else if (m1 >= l && m2 < l) {
            cout << "R" << endl;
        } else if (m2 >= l && m1 < l) {
            cout << "T" << endl;
        }
       //cout << m1 << ' ' << m2 << endl;
        cout << t;
    }
}