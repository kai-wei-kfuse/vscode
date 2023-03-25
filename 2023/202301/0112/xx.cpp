#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int maxn = 1e9;
    for (int i = 1; i <= n; i++) {
        int a = i;
        int b = n;
        int cnt = 0;
        while (a != b) {
            if (a > b) {
                swap(a, b);
            }
            cnt += b / a;
            b = b % a;
            if (b == 0) {
                break;
            }
        }
        if (a == 1) {
            
            maxn = min(maxn, cnt);
        }
    }
    cout << maxn - 1 << endl;
}