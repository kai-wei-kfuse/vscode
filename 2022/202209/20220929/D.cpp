#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        if (n != 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
// 3 6 7 9 11 13 17 18 19 21 23 26 29 31 33 37 39 41
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17