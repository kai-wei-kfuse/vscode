#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
const int N = 1e6 + 5;
int next_[N];
// void kmp(string s)
// {
//     int len = s.size();
//     s = " " + s;
//     for (int i = 2, j = 0; i <= len; i++)
//     {
//         while (j & s[i] != s[j + 1])
//             j = next_[j];
//         if (s[i] == s[j + 1])
//             j++;
//         next_[i] = j;
//     }
// }

vector<int> prefix_function(string s) {
  int n = (int)s.length();
  s=" "+s;
  vector<int> pi(n+1);
  for (int i = 2; i <= n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}


signed main()
{
    IOS;
    string s;
    cin >> s;
    int len = s.size();
    //kmp(s);
    vector<int >next_=prefix_function(s);
    for(auto i:next_){
        cout<<i<<' ';
    }cout<<endl;
    //next_[0] = -1;
    vector<int> cnt(len + 1, 0), ans(len + 1, 0);
    int x = len;
    // while (x)
    // {
    //     cnt[x] = 1;
    //     x = next_[x];
    // }
    // for (int i = 1; i <= len; i++)
    // {
    //     cnt[i] += cnt[i - 1];
    // }
    x = len;
    int tot = 0;
    while (x != -1 && x != 0)
    {
        x = next_[x];
        if (x != -1 && x != 0)
        {
            tot++;
            ans[tot] = x;
        }
    }
    sort(ans.begin() + 1, ans.begin() + tot + 1);
    // for(int i=1;i<=tot;i++){
    //     cout<<ans[i]<<' ';
    // }
    // cout<<endl;
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        // cout<<x<<'|';
        int minn = min(len - x, x - 1);
        cout << upper_bound(ans.begin() + 1, ans.begin() + tot + 1, minn) - ans.begin() - 1 << '\n';
        // cout<<min(cnt[len-x],cnt[x-1])<<'\n';
    }
}