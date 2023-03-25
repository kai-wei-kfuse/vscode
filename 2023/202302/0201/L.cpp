#include <bits/stdc++.h>
using namespace std;

int z[100005], p[100005];

void get_z(string s, int n) {
    z[1] = n;
    for (int i = 2, l, r = 0; i <= n; i++) {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);
        // 关键部分，通过盒子直接得出LCP长度（可能不是最长）
        while (s[1 + z[i]] == s[i + z[i]])
            // 暴力枚举位置，此时计算完的LCP是最终的LCP
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;  // 更新盒子
        // printf("i=%d z=%d [%d %d]\n",i,z[i],l,r);
    }
}
void get_p(string s, int n, string t, int m) {
    for (int i = 1, l, r = 0; i <= m; i++) {
        if (i <= r)
            p[i] = min(z[i - l + 1], r - i + 1);
        while (1 + p[i] <= n && i + p[i] <= m && s[1 + p[i]] == t[i + p[i]])
            p[i]++;
        if (i + p[i] - 1 > r)
            l = i, r = i + p[i] - 1;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(z, 0, sizeof z);
        memset(p, 0, sizeof p);
        string a, s_;
        cin >> a >> s_;
        string new_ = a;
        for (int i = 0; i < 26; i++) {
            new_[a[i] - 'a'] = i + 'a';
        }
        // cout << new_ << endl;

        string b;
        int len = s_.size();
        for (int i = 0; i < len; i++) {
            b += a[s_[i] - 'a'];
        }
        if (len == 1) {
            cout << s_;
            cout << new_[s_[0] - 'a'];
            cout << endl;
        } else {
            string s = "?" + s_;
            // cout << b << endl << s << "!" << endl;
            b = "?" + b;
            get_z(s, s.size() - 1);
            get_p(s, s.size() - 1, b, b.size() - 1);
            int maxn = 0;
            int k = len;
            // p[len] = 0;
            // for (int i = 1; i <= len; i++) {
            //     cout << p[i] << ' ';
            // }
            // cout << endl;
            for (int i = 1; i <= len; i++) {
                if (i + p[i] - 1 == len && i >= p[i]) {
                    k = i - 1;
                    break;
                }
            }
            // cout << k << endl;
            for (int i = 0; i < k; i++) {
                cout << s_[i];
            }

            for (int i = 0; i < k; i++) {
                cout << new_[s_[i] - 'a'];
            }
            cout << endl;
        }
    }
}
