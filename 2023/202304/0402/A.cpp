#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tmp = 0;
        int num = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tmp ^= x;
        }
        if (n % 2) {
            for (int i = 0; i < 2e8; i++) {
                if ((tmp ^ i)== 0) {
                    cout << i << endl;
                    break;
                }
            }
        } else {
            if (tmp == 0) {
                cout << 0 << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
}