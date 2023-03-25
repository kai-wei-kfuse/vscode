#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int next1[105], next2[105];
const int P = 131;
ull h1[105], p[105], h2[105];

ull get(int l, int r, ull h[]) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        string f1 = ve[1], f2 = ve[1];
        reverse(f2.begin(), f2.end());
        f1 = "?" + f1;
        f2 = "?" + f2;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h1[i] = h1[i - 1] * P + f1[i];
            h2[i] = h2[i - 1] * P + f2[i];
        }
        int len = f1.size();
        int num = 0, longest = 0;
        for (int i = 0; i < len; i++) {
            for (int l = 1; l + i - 1 < len; i++) {
                ull tmp1 = get(i, i + l - 1, h1);          // 正
                ull tmp2 = get(len - l, len - i - 1, h2);  // 反
                for (int j = 2; j <= n; j++) {
                    for (int k = 0; k + l - 1 < len; k++) {
                        if()
                    }
                }
            }
        }
    }
}