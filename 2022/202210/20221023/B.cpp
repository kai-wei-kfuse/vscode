#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans(n + 1);
        int len = n / 2;
        int i, j;
        for (i = 1, j = len + 1; j <= n, i <= len; i++, j++) {
            cout << j << ' ' << i << ' ';
        }
        if (n % 2 != 0)
            cout << j;
        cout << endl;
    }
}