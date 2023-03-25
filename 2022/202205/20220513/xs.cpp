#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int f1[N];
int f2[N];
void init() {
    for (int i = 1; i < N; i++) {
        f1[i] = i;
        f2[i] = i;
    }
}

signed main() {
    freopen("in.txt", "r", stdin);  //输入重定向，输入数据将从in.txt文件中读取
    freopen("out.txt", "w", stdout);  //输出重定向，输出数据将保存out.txt文件中
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != 0)
            f1[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != 0)
            f2[i] = x;
    }
    map<int, int> mp;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        if (f1[i] != f2[i] && mp[x] == 0) {
            while (f1[x] != x && mp[x] == 0) {
                mp[x] = 1;
                int y = x;
                x = f1[x];
                f1[y] = y;
                cnt++;
            }
        }
    }
    mp.clear();
    for (int i = 1; i <= n; i++) {
        int x = i;
        if (f1[i] != f2[i] && mp[i] == 0) {
            while (f2[x] != x) {
                mp[x] = 1;
                x = f2[x];
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
/*
 7
3 5 4 0 7 0 0
3 5 0 6 7 0 0

 */
