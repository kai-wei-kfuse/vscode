#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
const int N = 1e6 + 5;
int next_[N];
void kmp(string s)
{
    int len = s.size();
    s = " " + s;
    for (int i = 2, j = 0; i <= len; i++)
    {
        while (j & s[i] != s[j + 1])
            j = next_[j];
        if (s[i] == s[j + 1])
            j++;
        next_[i] = j;
    }
}

int main()
{
    IOS;
    string s;
    cin >> s;
    int len = s.size();
    kmp(s);
    vector<int> cnt(len + 1);
    int x = next_[len];
    while (x)
    {
        cnt[x] = 1;
        x = next_[x];
    }
    for (int i = 1; i <= len; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        // cout<<x<<'|';
        cout<<min(cnt[len-x],cnt[x-1])<<'\n';
    }
}