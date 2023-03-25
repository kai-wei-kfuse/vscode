#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e6;
bool not_prime[maxn + 5];
int prime[maxn + 5], tot = 0;
int low[maxn + 5];
void sieve() {
    for (int i = 2; i <= maxn; i++) {
        if (!not_prime[i]) {
            prime[++tot] = i;
            low[i] = i;
        }
        for (int j = 1; j <= tot && i * prime[j] <= maxn; j++) {
            not_prime[i * prime[j]] = 1;
            low[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}
signed main() {
    int t;
    cin >> t;
    sieve();
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int> ve(n + 1);
        vector<int> a[e + 1];
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        for (int i = 1; i <= e; i++) {
            for (int j = i; j <= n; j += e) {
                a[i].push_back(ve[j]);
            }
        }
        //  for (int i = 1; i <= e; i++) {
        //     for (auto k : a[i]) {
        //         cout << k << ' ';
        //     }
        //    cout << endl;
        // }
        int l = 0, r = 0;
        int ans = 0;
        for (int i = 1; i <= e; i++) {
            int x = a[i].size();
            if (x > 1) {
                for (int j = 0; j < x; j++) {
                    if (!not_prime[a[i][j]] && a[i][j] != 1) {
                        int le = j, ri = j;
                        while (le > 0 && a[i][le - 1] == 1)
                            le--;
                        while (ri < x - 1 && a[i][ri + 1] == 1)
                            ri++;
                        if (le != j || ri != j)
                            ans += (ri - j + 1) * (j - le + 1) - 1;
                    }
                }
            }
            // cout << ans << endl;
        }
        cout /* << "ans:"  */<< ans << endl;
    }
}