#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
string a[42];
int vis[42];
int ans, n, same;
int chack(string a, string b) {
    int sum = 0, res = 0x3f3f3f;
    // for (int j = 0; j < a.length(); j++) {
    //     if (b[0] == a[j]) {
    //         int k = j;
    //         for (int i = 0; i < b.length(), k < a.length(); i++, k++) {
    //             if (b[i] != a[k]) {
    //                 sum = 0;
    //                 break;
    //             }
    //             sum++;
    //         }
    //     }
    //     if (sum != 0)
    //         res = min(res, sum);
    //     sum = 0;
    // }
    // same = res;
    // // cout << same << endl;
    // if (same == b.length())
    //     return 0;
    // return same > 0;
    for (int i = 1; i < min(a.length(), b.length()); i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (b[j] != a[a.length() - i + j]) {
                flag = 0;
            }
        }
        if (flag)
            return same = i;
    }
    return 0;
}
void dfs(string s, int len) {
    ans = max(len, ans);
    for (int i = 1; i <= n; i++) {
        if (vis[i] < 2 && chack(s, a[i])) {
            vis[i]++;
            // cout << a[i] << ' ' << same << endl;
            dfs(a[i], len + a[i].length() - same);
            vis[i]--;
        }
    }
    // cout << endl;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    char f;
    cin >> f;
    for (int i = 1; i <= n; i++) {
        if (a[i][0] == f) {
            vis[i]++;
            dfs(a[i], a[i].length());
            vis[i]--;
        }
    }
    cout << ans;
}