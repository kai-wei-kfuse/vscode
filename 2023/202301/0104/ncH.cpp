#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> res1(n + 2, 0);
        vector<long long> res2(n + 2, 0);
        vector<long long> res3(n + 2, 0);
        for (int i = 1; i <= k; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 1) {
                res1[y]++;
            } else if (x == 2) {
                res2[y]++;
            } else {
                res3[y]++, res3[y + 1]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            res1[i] += res1[i - 1];
            res1[i] %= mod;
            res2[i] += res2[i - 1];
            res2[i] %= mod;
            res3[i] += res3[i - 1];
            res3[i] %= mod;
        }
        for (int i = 1; i <= n; i++) {
            res2[i] += res2[i - 1];
            res2[i] %= mod;
            res3[i] += res3[i - 1];
            res3[i] %= mod;
        }
        for (int i = 1; i <= n; i++) {
            res3[i] += res3[i - 1];
            res3[i] %= mod;
        }
        for (int i = 1; i <= n; i++) {
            cout << (res1[i] + res2[i] + res3[i]) % mod << ' ';
        }
        cout << endl;
    }
    int 😊= 1;
}