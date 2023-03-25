#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef unsigned long long ull;
const int N = 1000010, P = 131;
int n, len, llen;
string s, x;
// ull mod = 212370440130137957 或 1<<30,或者可以写双哈希，进制数131差不多了
ull mod = 212370440130137957;
// p[i]=P^i, h[i]=s[1~i]的hash值
ull p[N], h[N], h_[N];

// 预处理 hash函数的前缀和
void init() {
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= llen; i++) {
        p[i] = (__int128)p[i - 1] * P % mod;
        h[i] = ((__int128)h[i - 1] * P % mod + (ull)x[i]) % mod;
    }
}
void init_() {
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= llen; i++) {
        p[i] = (__int128)p[i - 1] * P % mod;
        h_[i] = ((__int128)h_[i - 1] * P % mod + (ull)x[i]) % mod;
    }
}
// 计算s[l~r]的 hash值
ull get(int l, int r) {
    return (((__int128)h[r] - (__int128)h[l - 1] * p[r - l + 1] % mod) % mod +
            mod) %
           mod;
}
ull get_(int l, int r) {
    return (((__int128)h_[r] - (__int128)h_[l - 1] * p[r - l + 1] % mod) % mod +
            mod) %
           mod;
}
// 判断两子串是否相同
bool substr(int l1, int r1, int l2, int r2) {
    return get(l1, r1) == get(l2, r2);
}

int main() {
    IOS cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        s = "?" + s;
        len = s.size() - 1;
        int l = 1, r = len;
        while (l < r && s[l] == s[r]) {
            l++, r--;
        }
        // cout << l << ' ' << r << endl;
        //  cout << "!" << endl;
        if (l >= r || len == 1) {
            cout << "Yes" << '\n';
            continue;
        }
        // cout << "?" << endl;
        x = s.substr(l, r - l + 1);
        // cout << x << endl;
        llen = x.size();

        x = "?" + x;
        init();
        reverse(x.begin() + 1, x.end());
        init_();
        int flag = 1;
        for (int i = 1; i * 2 <= llen; i++) {
            // cout << llen - i + 1 << ' ' << llen << " " << llen - i << endl;
            if (substr(1, i, llen - i + 1, llen) &&
                get_(i + 1, llen - i) == get(i + 1, llen - i)) {
                flag = 0;
                break;
            }
        }
        // cout << "111 " << flag << endl;
        if (flag) {
            for (int i = 1; i * 2 < llen; i++) {
                // cout << i + i - 1 << ' ' << i * 2 << endl;
                if (substr(1, i, i + 1, i * 2) &&
                    get_(1, llen - i * 2) == get(i * 2 + 1, llen)) {
                    flag = 0;
                    break;
                }
            }
        }
        // cout << "222 " << flag << endl;
        if (flag) {
            for (int i = 1; i * 2 < llen; i++) {
                // cout << i + i - 1 << ' ' << i * 2 << endl;
                if (get_(1, i) == get_(i + 1, i * 2) &&
                    get(1, llen - i * 2) == get_(i * 2 + 1, llen)) {
                    flag = 0;
                    break;
                }
            }
        }
        // cout << "333 " << flag << endl;
        if (flag == 1) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
}