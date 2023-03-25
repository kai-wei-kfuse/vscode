#include <iostream>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        int ans = 0;
        if (a == "Alice") {
            int rem = n % 5;
            ans = (n / 5) * 2;
            if (rem == 1 || rem == 2 || rem == 3)
                ans++;
            else if (rem == 4)
                ans += 2;
        } else {
            int rem = (n - 2) % 5;
            ans = ((n - 2) / 5) * 2 + 1;
            if (rem == 1 || rem == 2 || rem == 3)
                ans++;
            else if (rem == 4)
                ans += 2;
        }
        cout << ans << '\n';
    }
}