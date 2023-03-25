#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int main() {
    int t;
    IOS;
    cin >> t;
    while (t--) {
        int n, k, tmp;
        cin >> n >> k;
        set<int> se;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            se.insert(tmp);
        }
        int a = k, b = k, cnt = 0, mex = 0, maxn = 0, flag = 0;
        for (int i = 0; ; i++) {
            if (!se.count(i)) {
                if (i & 1 && a > 0) {
                    a--;
                } else if (i % 2 == 0 && b > 0) {
                    b--;
                } else {
                    mex = i;
                    break;
                }
            }
        }
        if (mex & 1) {
            cout << "Bob" << '\n';
        } else {
            cout << "Alice" << '\n';
        }
    }
}