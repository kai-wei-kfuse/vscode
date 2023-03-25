#include <bits/stdc++.h>
using namespace std;
typedef long long l;
int main() {
    int n, x;
    cin >> n;
    l maxv = INT_MIN;
    l maxv_d = 0;
    for (int i = 0, length = 1, depth = 1; i < n; depth++, length *= 2) {
        l sum = 0;
        for (int j = 0; j < length && i < n; j++, i++) {
            cin >> x;
            sum += x;
        }
        if (sum > maxv) {
            maxv = sum;
            maxv_d = depth;
        }
    }
    cout << maxv_d;
    return 0;
}