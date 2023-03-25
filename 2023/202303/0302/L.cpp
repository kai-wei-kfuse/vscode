#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        int n;
        cin >> n;
        cout << "Case #" << cnt++ << ": ";
        if (n < 7) {
            cout << "Draw" << endl;
        } else if (n >= 7 && n < 16) {
            if (n & 1) {
                cout << "Panda" << endl;
            } else {
                cout << "Draw" << endl;
            }
        } else {
            if (n & 1) {
                cout << "Panda" << endl;
            } else {
                cout << "Sheep" << endl;
            }
        }
    }
}