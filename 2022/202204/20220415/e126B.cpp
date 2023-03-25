#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
const ll mod = 32768;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll tmp, sum = 0;
    while (n--) {
        cin >> tmp;
        sum = 0;
        cout << (tmp * mod / __gcd(tmp, mod)) / mod << endl;
        while (tmp != 0) {
            tmp *= 2;
            tmp %= mod;
            sum++;
            // cout << tmp << endl;
        }
        cout << sum << endl;
    }
}