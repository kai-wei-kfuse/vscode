#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long ans = 0;
    for (auto i : s) {
        ans *= 26;
        ans += i - 'A' + 1;
    }
    cout << ans << endl;
}