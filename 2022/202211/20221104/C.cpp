#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int minn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            minn = min(minn, ve[i]);
        }
        if (minn == ve[1])
            cout << "Bob" << endl;
        else {
            cout << "Alice" << endl;
        }
    }
}