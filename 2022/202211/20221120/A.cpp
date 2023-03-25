#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b >= n - 1 && a + b != 2 * n) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}