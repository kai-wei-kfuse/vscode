#include <bits/stdc++.h>
using namespace std;
int next_[1000005];
int main() {
    int n, cnt = 1;
    cin >> n;
    while (n) {
        string s;
        cin >> s;
        s = "?" + s;
        cout << "Test case #" << cnt << endl;
        cnt++;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = next_[j];
            if (s[i] == s[j + 1])
                j++;
            next_[i] = j;
            if (i % (i - next_[i]) == 0 && i / (i - next_[i]) > 1) {
                cout << i << ' ' << i / (i - next_[i]) << endl;
            }
        }
        cin >> n;
        cout << endl;
    }
}