#include <bits/stdc++.h>
using namespace std;
//#define int long long

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

struct Hash {
    const long long mod = 1e9+7;  // 哈希模数
    const long long P = 13331;              // 进制数
    vector<long long> h, p;
    Hash(string s)
        : h(s.size() + 2), p(s.size() + 2) {  // 初始化构造函数，s表示参数,冒号后面表示需要初始化的成员变量
        int n = s.size();
        p[0] = 1;
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * P + s[i]) % mod;
            p[i + 1] = p[i] * P % mod;
        }
    };  // 这段构造当黑盒子就好

    long long get(int l, int r) {  // 字符串长度是len，则这里的l和r是1到len
        return (h[r + 1] + __int128(h[l]) * (mod - p[r + 1 - l])) % mod;
    };
};

signed main() {
    ios;
    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        Hash h1(s1), h2(s2), h3(s3);
        unordered_map<int, int> mp;
        int len1 = s1.size() - 1, len2 = s2.size() - 1, len3 = s3.size() - 1;
        int has = h2.get(1, len2);  // has是s2的哈希值
        for (int i = 0; i <= len1; i++) {
            int tmp;
            if (i == 0) {
                tmp = (has * h1.p[len1]% h1.mod + h1.get(1, len1)) % h1.mod;
            } else if (i == len1) {
                tmp = (h1.get(1, len1) * h2.p[len2]% h1.mod + has) % h1.mod;
            } else {
                tmp = ((h1.get(1, i) * h2.p[len2])% h1.mod * h1.p[len1 - i] % h1.mod + has * h1.p[len1 - i] % h1.mod + h1.get(i + 1, len1)) % h1.mod;
            }
            //cout << i << " " << s1.substr(1, i) << "|" << s2 << "|" << s1.substr(i + 1) << ' ' << tmp << endl;
            mp[tmp]++;
        }
        int ans = 0;
        int len = len2 + len1;
        for (int l = 1; l + len - 1 <= len3; l++) {
            int tmp = h3.get(l, l + len - 1);

            if (mp[tmp] > 0) {
                //cout << s3.substr(l, len) << ' ' << tmp << " " << mp[tmp] << endl;
                ans += mp[tmp];
            }
        }
        cout << ans << endl;
    }
}