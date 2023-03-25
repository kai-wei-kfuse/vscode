#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int flag = 0;
        if (k & 1) {
            cout << "Yes" << '\n';
            for (int i = 1; i <= n; i += 2) {
                cout << i << ' ' << i + 1 << '\n';
            }
        } else {
            if (k == 0) {
                cout << "No" << '\n';
            } else {
                for (int i = 2; i <= n; i += 4) {
                    if ((i + k) % 4 != 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) {
                    cout << "No" << '\n';
                } else {
                    cout << "Yes" << '\n';
                    for (int i = 2; i <= n; i += 2) {
                        if (i % 4 == 0) {
                            cout << i - 1 << ' ' << i << '\n';
                        } else {
                            cout << i << ' ' << i - 1 << '\n';
                        }
                    }
                }
            }
        }
    }
}