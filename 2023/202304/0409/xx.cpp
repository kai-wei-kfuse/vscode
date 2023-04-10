#include <bits/stdc++.h>
using namespace std;

struct xx {
    int t, d, l;
};
bool cmp(xx a, xx b) {
    return a.d + a.t < b.d + b.t;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<xx> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].t >> a[i].d >> a[i].l;
        }
        sort(a.begin() + 1, a.end(), cmp);
        int now = 0;
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (now > a[i].d + a[i].t) {
                flag = 1;
                break;
            }
            now += a[i].l;
        }
        if (flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}