#include <bits/stdc++.h>
using namespace std;

int next_[1000005];

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        s = "?" + s;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = next_[j];
            if (s[i] == s[j + 1])
                j++;
            next_[i] = j;
        }
        cout << n - next_[n] << endl;
    }
}