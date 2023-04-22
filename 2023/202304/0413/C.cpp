#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int x = sum / n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}