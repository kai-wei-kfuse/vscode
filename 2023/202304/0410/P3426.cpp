#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    s = "?" + s;
    vector<int> next_(len + 1);
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && s[i] != s[j + 1])
            j = next_[j];
        if (s[j + 1] == s[i]) j++;
        next_[i] = j;
    }
    vector<int> dp(len + 1,0), bu(len + 1, 0);
    for (int i = 1; i <= len; i++) {
        dp[i] = i;
        if (bu[dp[next_[i]]] >= i - next_[i]) dp[i] = dp[next_[i]];
        bu[dp[i]] = i;
    }
    // for(int i = 1; i <= len; i++)
    //     cout << s[i] << " ";
    // cout << endl;
    // for(int i = 1; i <= len; i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    cout << dp[len] << endl;
}