#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1)
                num1++;
        }
        int flag = 0, flag2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] == 1) {
                num2++;
            }
            if (b[i] > a[i]) {
                flag++;
            }
            if (b[i] < a[i]) {
                flag2++;
            }
        }
        int p = 0;
        if (min(flag2, flag) >= 1) {
            p = 1;
        }
        cout << abs(flag2 - flag) + p << endl;
    }
}
