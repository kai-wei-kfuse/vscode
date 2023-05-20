#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
const int N = 1e6 + 5;
int next_[N];
char s[N];
inline void kmp(char s[])
{
    int len = strlen(s+1);
    for (int i = 2, j = 0; i <= len; i++)
    {
        while (j & s[i] != s[j + 1])
            j = next_[j];
        if (s[i] == s[j + 1])
            j++;
        next_[i] = j;
    }
}

signed main()
{
    //IOS;
    scanf("%s",s+1);
    kmp(s);
    int len = strlen(s+1);
    vector<int> cnt(len + 1, 0);
    int x = len;
    while (next_[x])
    {
        cnt[next_[x]] = 1;
        x = next_[x];
    }
    for (int i = 1; i <= len; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    // for(int i=1;i<=len;i++){
    //     cout<<next_[i]<<' ';
    // }
    // cout<<endl;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int x;
        cin >> x;
        // cout<<x<<'|';
        //cout<<min(cnt[len-x],cnt[x-1])<<endl;
        printf("%d\n",min(cnt[len-x],cnt[x-1]));
    }
}