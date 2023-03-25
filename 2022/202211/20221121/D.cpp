#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int flag = 0;
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (ve[i] > ve[i - 1]) {
                flag = 1;
            }
            if (ve[i] < ve[i - 1] && flag) {
                ans = 0;
            }
        }
        if (ans) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}