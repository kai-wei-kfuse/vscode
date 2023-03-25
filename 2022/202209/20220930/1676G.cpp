#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> tr[n + 5];
        for (int i = 2; i <= n; i++) {
            int tmp;
            cin >> tmp;
            tr[tmp].push_back(i);
        }
        cin >> s;
        dp(1);
    }
}