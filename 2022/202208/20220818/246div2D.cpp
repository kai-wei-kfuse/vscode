#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

char a[1000005], b[1000005];
int next_[1000005], z[1000005], p[1000005], l[1000005];
map<int, int> mp;

int main() {
    cin >> a + 1;
    int len = strlen(a + 1);
    vector<int> ans(len + 1);
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && a[i] != a[j + 1])
            j = next_[j];
        if (a[i] == a[j + 1])
            j++;
        next_[i] = j;
    }
    for (int i = 1; i <= len; i++) {
        cout << next_[i] << ' ';
    }
    int cnt = 0;
    for (int i = len; i >= 1; i = next_[i]) {
        // cout << i << ' ';
        l[++cnt] = i;
    }
    // for (int i = 1; i <= len; i++)
    //     ans[next_[i]]++;
    // for (int i = len; i >= 1; i--)
    //     ans[next_[i]] += ans[i];
    // for (int i = 1; i <= len; i++) {
    //     ans[i]++;
    // }
    for (int i = len; i >= 1; i--)
        ans[next_[i]] += ++ans[i];
    cout << cnt << '\n';
    for (int i = cnt; i >= 1; i--) {
        cout << l[i] << ' ' << ans[l[i]] << '\n';
    }
}
