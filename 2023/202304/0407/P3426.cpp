#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int next_[N];

int main() {
    string s;
    cin >> s;
    int len = s.size();
    s = "?" + s;
    int ans = 0;
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && s[i] != s[j + 1])
            j = next_[j];
        if (s[i] == s[j + 1]) j++;
        next_[i] = j;
    }
    int x = len;
    while (next_[x]) {
        x = next_[x];
        cout << x << endl;
    }
}