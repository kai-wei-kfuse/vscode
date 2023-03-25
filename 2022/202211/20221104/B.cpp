#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (n + 1) / 2 << endl;
        int x = n * 3;
        for (int i = 1, j = x; i <= x / 2; i += 3, j -= 3) {
            cout << i << ' ' << j << endl;
        }
    }
}