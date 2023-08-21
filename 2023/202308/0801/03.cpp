#include <bits/stdc++.h>
#
using namespace std;

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
const int N = 1e5 + 5;
int p[N << 1];
char ma[N << 1];
char a[N];
int res[N << 1];
int ans = 0;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

void manacher(string s, int len);
inline void solve() {
    string s;
    cin >> s;
    // cout << "s" << endl;
    int len = s.size();
    // cout << "ss" << endl;
    manacher(s, len);
    // for (int i = 1; i <= 2 * len; i++) {
    //     cout << p[i] << ' ';
    // }
    // cout << endl;
    cout << ans << '\n';
}

inline void manacher(string s, int len) {
    int k = 0;
    ma[k++] = '$';
    ma[k++] = '#';
    for (int i = 0; i < len; i++) {  //  预处理
        ma[k++] = s[i];
        ma[k++] = '#';
    }
    ma[k] = '&';
   // Hash_ h(ma);
   // vector<int> cnt(k + 1);
   // vector<pair<int,int>> idx[k + 1];
    // cout << ma << endl;
    int mr = 0, c = 0;  // mr表示回文串的最右边界，c就是这个回文串的中心
    for (int i = 1; i < k; i++) {
        if (i < mr) {
            //  如果i在回文串内部，那么p[i]至少等于p[2 * c - i]，因为i关于c对称，所以p[i]至少等于p[c] - (i - c)
            p[i] = min(p[2 * c - i], c + p[c] - i);
            // if (ma[i] == '#' && p[2 * c - i] > 1) {
            //     int ri=upper_bound(idx[2 * c - i].begin(),idx[2 * c - i].end(),make_pair(p[i],0),cmp)-idx[2 * c - i].begin();
            //     if(ri>0&&idx[2 * c - i][ri-1].first==p[i]){
            //         ri--;
            //     }
            //     ans+=idx[2 * c - i][ri].second;
            //     copy(idx[2 * c - i].begin(),idx[2 * c - i].begin()+ri,idx[i].begin());
            //    // ans += min(cnt[2 * c - i], p[2 * c - i] / 2);
            //    // cnt[i] += min(cnt[2 * c - i], p[2 * c - i] / 2);
            //     // cout << cnt[2 * c - i] << " " << p[2 * c - i] / 2 << "==" << 2 * c - i << endl;
            // }
            //  但是如果p[2 * c - i]大于c + p[c] - i，那么p[i]就等于c + p[c] - i
        } else {
            p[i] = 1;  //  如果i不在回文串内部，那么p[i]至少为1
        }
        while (ma[p[i] + i] == ma[i - p[i]]) {
            p[i]++;
            // if (ma[i] == '#') {
            //     // cout << i << ma[i] << ' ' << p[i] << " "
            //     //      << "l:" << i - p[i] + 1 << " " << i - 1 << " r:" << i + 1 << " " << i + p[i] - 1 << " ";
            //     // cout << "mid:" << (2 * i - p[i]) / 2 << " p[mid]:" << p[(2 * i - p[i]) / 2] << endl;
            //     if (p[(2 * i - p[i]) / 2] >= p[i] / 2 && i + p[i] < k && h.get(i - p[i] + 1, i - 1) == h.get(i + 1, i + p[i] - 1)) {
            //         ans++;
            //         //  cout << "ans++" << endl;
            //         cnt[i]++;
            //         idx[i].push_back({i + p[i] - 1, cnt[i]});
            //     }
            // }
        }
        //  从p[i]开始向两边扩展，直到不是回文串为止
        if (p[i] + i > mr) {  //  如果i + p[i] > mr，那么更新mr和c
            mr = p[i] + i;    //  mr表示回文串的最右边界
            c = i;            //  c就是这个回文串的中心
        }
    }
    // for(int i=0;i<k;i++){
    //     cout<<p[i]<<' ';
    // }
    // cout << endl;
    for (int i = 1; i <= k; i+=2) {
        if (ma[i] == '#') {
            for (int j = i-1; j >= i-p[i]/2; j--) {
               // cout<<i<<' '<<j<<' '<<i-j<<' '<<i-1<<' '<<i+1<<' '<<i+j<<endl;
                if (p[j]+j>=i) {
                    ans++;
                   // res[i+i-j]++;
                   // cout << i + i - j << " ";
                }
            }
        }
    }
    // for (int i = 1; i <= len; i++) {
    //     ans+= res[2*i-1];
    // }
    // for (int i = 0; i < k; i++) {
    //     cout << cnt[i] << ' ';
    // }
}
/*
$ # a # b # a # a # b # a #
1 1 2 1 4 1 2 7 2 1 4 1 2 1
6
*/

signed main() {
    ios;
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        // cout << "x" << endl;
        solve();
    }
}