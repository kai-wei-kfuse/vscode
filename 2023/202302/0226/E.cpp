#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    //cout << (3 << 2) << endl;
    while (t--) {
        int n;
        cin >> n;
        int flag = -1;
        int ri = 0, x = 0;
        int a = 0, b = 0;
        do {
            x++;
            if (flag == -1 && !(n & 1) ) {
                flag = 0;
            }
            else if (flag == -1 && (n & 1)) {
                ri = 1;
                break;
            }
            else if (flag == 0 && n & 1 == 1) {
                //cout << x << endl;
                a += (3 << (x - 2));
                b += (1 << (x - 2));
                flag = -1;
            }
            n >>= 1;
            //cout << flag;
            // cout << n;

        } while (n );
        if (ri) {
            cout << "-1" << endl;
        } else
            cout << a << ' ' << b << endl;
    }
}