#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            if (i > 1 && ve[i] != ve[i - 1]) {
                flag = 0;
            }
        }
        sort(ve.begin() + 1, ve.end(), greater<int>());
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << ve[n] << ' ';
            for (int i = 1; i < n; i++) {
                cout << ve[i] << ' ';
            }
            cout << endl;
        }
    }
}