#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int fir = s[0];
        int now = s[0];
        int id = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] <= now) {
                now = s[i];
                id = i;
            }
        }
        cout << s[id];
        for (int i = 0; i < n; i++) {
            if (i != id) {
                cout << s[i];
            }
        }
        cout << endl;
    }
}