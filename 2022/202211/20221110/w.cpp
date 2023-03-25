#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0;
    for (int k = 51; k <= 51; k+=2) {
        ans = 0;
        for (int i = 1; i <= 100000; i++) {
            //cout << i << ' ' <<((k*i)^k)<<' '<< ((k * i) ^ k) % k << " ";
            //cout << __gcd(((k * i) ^ k), k) << endl;
            if(__gcd(((k * i) ^ k), k)==1)
                ans++;
        }
        cout << ans << endl;
    }
}