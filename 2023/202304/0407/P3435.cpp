#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int next_[N];
string s;

int main() {
    int n;
    cin >> n;
    cin >> s;
    s = "?" + s;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1])
            j = next_[j];
        if (s[i] == s[j + 1]) j++;
        next_[i] = j;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        while(next_[x]) x = next_[x];
        if(next_[i])next_[i] = x;
        ans += i-x;
    }
    cout << ans;
}