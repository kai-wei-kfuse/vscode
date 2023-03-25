#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<char> ve(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int flag0 = -1, flag1 = -1, last0 = -1, last1 = -1;
        for (int i = n; i >= 1; i--) {
            if (flag0 == -1 && ve[i] == '0') {
                flag0 = i;
            }
            if (flag0 != -1 && flag1 == -1 && ve[i] == '1') {
                flag1 = i;
            }
            if (ve[i] == '0')
                last0 = i;
            if (ve[i] == '1')
                last1 = i;
        }
        if (flag1 > 0 && flag1 < flag0) {
            if (last0 == 1) {
                for (int i = 1; i < last1; i++) {
                    cout << ve[i];
                }
            }
            for (int i = flag0; i <= n; i++) {
                cout << ve[i];
            }
        } else {
            for (int i = 1; i <= n; i++) {
                cout << ve[i];
            }
        }
        cout << '\n';
    }
}