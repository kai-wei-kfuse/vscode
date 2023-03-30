#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int p[N << 1];
char ma[N << 1], ma_[N << 1];
char a[N], a_[N];

void manacher(char s[], int len) {
    int k = 0;
    ma_[k] = '$';
    ma[k++] = '$';
    ma_[k] = '#';
    ma[k++] = '#';
    for (int i = 0; i < len; i++) {  //  预处理
        ma_[k] = a_[i];
        ma[k++] = s[i];
        ma_[k] = '#';
        ma[k++] = '#';
    }
    ma_[k] = '&';
    ma[k] = '&';
    int mr = 0, c = 0;  // mr表示回文串的最右边界，c就是这个回文串的中心
    for (int i = 1; i < k; i +=2) {
        if (i < mr) {                                //  如果i在回文串内部，那么p[i]至少等于p[2 * c - i]，因为i关于c对称，所以p[i]至少等于p[c] - (i - c)
            p[i] = min(p[2 * c - i], c + p[c] - i);  //  但是如果p[2 * c - i]大于c + p[c] - i，那么p[i]就等于c + p[c] - i
        } else {
            p[i] = 1;  //  如果i不在回文串内部，那么p[i]至少为1
        }
        while (ma_[p[i] + i] == ma[i - p[i]])
            p[i]++;           //  从p[i]开始向两边扩展，直到不是回文串为止
        if (p[i] + i > mr) {  //  如果i + p[i] > mr，那么更新mr和c
            mr = p[i] + i;    //  mr表示回文串的最右边界
            c = i;            //  c就是这个回文串的中心
        }
    }
}
/*
7
1000110
$ # 0 # 1 # 1 # 1 # 0 # 0 # 1 # 
$ # 1 # 0 # 0 # 0 # 1 # 1 # 0 # 
  0   2   0   0   4   0   2   0 4
*/
signed main() {
    int n;
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            a_[i] = '0';
        } else {
            a_[i] = '1';
        }
    }
    int ans = 0;
    manacher(a, n);
    for (int i = 0; i <= 2 * n + 1; i++) {
        if ((p[i] - 1) % 2 == 0) {
            // cout<<p[i] - 1<<' ';
            ans += max(0LL, (p[i] - 1) / 2);
        }
        // else{
        //     cout <<"  ";
        // }
    }
    cout << ans << '\n';
}