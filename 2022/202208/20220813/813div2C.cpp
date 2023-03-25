#include <iostream>
#include <map>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int a[100005];

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp, mp2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]] = i;
        }
        int ans = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] > a[i + 1]) {
                int k = i, flag = i;
                int l = flag, j;
                // l~r(1~i)
                while (k >= 1) {
                    if (mp2[a[k]] == 1) {
                        k--;
                    } else if (mp[a[k]] <= flag && mp2[a[k]] == 0) {
                        mp2[a[k]] = 1;
                        ans++;
                        k--;
                    } else if (mp[a[k]] > flag && mp2[a[k]] == 0) {
                        // l~r(i~mp[a[r]])
                        j = mp[a[k]];
                        while (j > l) {
                            if (mp2[a[j]] == 0) {
                                mp2[a[j]] = 1;
                                ans++;
                                j--;
                            }
                        }
                        l = mp[a[k]];
                    }
                }
                break;
            }
        }
        cout << ans << '\n';
    }
}