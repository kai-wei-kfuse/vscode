#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        while (a % b != 0) {
            b = a % b;
        }
        if (b == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}