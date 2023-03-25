#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        if (a == b) {
            cout << "0" << endl;
            continue;
        }
        if (abs(r - l) < x) {
            cout << "-1" << endl;
            continue;
        }
        if (abs(a - b) >= x) {
            cout << "1" << endl;
            continue;
        }
        if (abs(r - b) >= x && abs(r - a) >= x) {
            cout << "2" << endl;
            continue;
        } else if (abs(l - b) >= x && abs(l - a) >= x) {
            cout << "2" << endl;
            continue;
        }
        if (abs(r - b) < x) {
            if (abs(l - b) < x) {  //
                cout << "-1" << endl;
            } else {
                if (abs(l - a) >= x) {
                    cout << "2" << endl;
                } else if (abs(r - a) >= x) {
                    cout << "3" << endl;
                } else if (abs(r - a) < x && abs(l - a) < x) {
                    cout << "-1" << endl;
                }
            }
            continue;
        }
        if (abs(l - b) < x) {
            if (abs(r - b) < x) {  //
                cout << "-1" << endl;
            } else {
                if (abs(r - a) >= x) {
                    cout << "2" << endl;
                } else if (abs(l - a) >= x) {
                    cout << "3" << endl;
                } else if (abs(r - a) < x && abs(l - a) < x) {
                    cout << "-1" << endl;
                }
            }
            continue;
        }
    }
}