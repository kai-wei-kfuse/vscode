#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int even = 0, odd = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            if (ve[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (odd == 0 && even > 0) {
            cout << "Alice" << endl;
        } else if (odd == 1 && (even + odd) % 2 == 0) {
            cout << "Alice" << endl;
        } else if (odd == 1 && (even + odd) % 2 != 0) {
            cout << "Bob" << endl;
        } else if (odd == 2) {
            cout << "Bob" << endl;
        } else if (odd > 2) {
            cout << "Alice" << endl;
        }
    }
}