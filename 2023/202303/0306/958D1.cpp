#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    map<pair<int,int>, int> mp;
    vector<pair<int,int> > ve;
    while (t--) {
        string s;
        cin >> s;

        int len = s.size();
        long long a = 0, b = 0, c = 0;
        int flag = 1, flag2 = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] != '+' && flag) {
                a *= 10;
                a += s[i] - '0';
            }
            if (!flag && s[i] != ')' && flag2) {
                b *= 10;
                b += s[i] - '0';
            }
            if (!flag2 && !flag) {
                c *= 10;
                c += s[i] - '0';
            }
            if (s[i] == '+') {
                flag = 0;
            }
            if (s[i] == ')') {
                flag2 = 0;
                i++;
            }
        }
        long long ab = a + b;
        int gcd_ = __gcd(ab, c);
        int a_ = ab / gcd_;
        int c_ = c / gcd_;
        // cout << a << ' ' << b << ' ' << c <<" "<<(a + b) / c<< endl;
        ve.push_back({a_,c_});
        mp[{a_,c_}]++;
    }
    for (auto i : ve) {
        cout << mp[i] << ' ';
    }
}