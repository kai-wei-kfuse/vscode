#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        vector<int> q1(n + 5), q2(n + 5);
        int len = 0;
        for (int i = 1; i <= n; i++) {
            if (q1[len] < ve[i]) {
                q1[++len] = ve[i];
            } else {
                int pos = lower_bound(q1.begin() + 1, q1.begin() + 1 + len, ve[i]) - q1.begin();
                q1[pos] = ve[i];
                len = max(len, pos);
            }
        }
        int len2 = 0;
        for (int i = 1; i <= n; i++) {
            if (q2[len2] > ve[i]) {
                q2[++len2] = ve[i];
            } else {
                int pos = lower_bound(q2.begin() + 1, q2.begin() + 1 + len2, ve[i],greater<int>()) - q2.begin();
                q2[pos] = ve[i];
                //cout << pos << endl;
                len2 = max(len2, pos);
            }
        }
        cout << len << ' ' << len2 << endl;
        cout << max(len,len2)<< endl;
    }
}