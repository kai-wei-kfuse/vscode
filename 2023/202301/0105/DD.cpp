#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) {
                cnt++;
            }
        }
        if (cnt == 2) {
            cout << "0" << endl;
        } else if (cnt == 0) {
            cout << "1" << endl;
        } else {
            cout << cnt - 1 << endl;
        }
    }
}