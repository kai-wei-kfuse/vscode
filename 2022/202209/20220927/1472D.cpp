#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> ve(n);
        for (int i = 0; i < n; i++) {
            cin >> ve[i];
        }
        sort(ve.begin(), ve.end());
        ll ansa = 0, ansb = 0;
        for (int i = n - 1; i >= 0; i -= 2) {
            if (ve[i] % 2 == 0)
                ansa+=ve[i];
        }
        for (int i = n - 2; i >= 0; i -= 2) {
            if (ve[i] % 2 != 0)
                ansb+=ve[i];
        }
        if (ansa > ansb)
            cout << "Alice" << endl;
        else if (ansa < ansb)
            cout << "Bob" << endl;
        else
            cout << "Tie" << endl;
    }
}