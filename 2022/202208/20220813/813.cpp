#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        map<int, int> mp;
        map<int, int> mp2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]] = i;
        }
        int cnt = 0;
        int i = n;
        int l = 1;
        int flag = 1;
        while (i > l && a[i - 1] <= a[i])
            i--;
        if (i > l) {
            int maxn = 0;
            for (int j = i - 1; j >= l; j--) {
                if (!mp2[a[j]]) {
                    mp2[a[j]] = 1;
                    cnt++;
                }
                maxn = max(maxn, mp[a[j]]);
            }
            l = i;
            if (maxn > l) {
                i = maxn;
            }
            for (int j = i - 1; j >= l; j--) {
                if (!mp2[a[j]]) {
                    mp2[a[j]] = 1;
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}