#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> a(10001);

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= 10000; i++) {
        a[i] = i * i;
    }
    while (t--) {
        int n;
        cin >> n;
        n--;
        vector<int> ve(n + 1);
        int now = lower_bound(a.begin(), a.end(), n) - a.begin();
        now = now * now;
        int f = n;
        // cout << now << '\n';
        for (int i = n, cnt = 0; i >= 0; i--) {
            ve[i] = (now - f) + cnt;
            // cout << n - i << endl;
            // cout << cnt << endl;
            cnt++;
            if (ve[i] == f) {
                f = i - 1;
                now = lower_bound(a.begin(), a.end(), i - 1) - a.begin();
                now = now * now;
                cnt = 0;
                // cout << now << endl;
            }
            // cout << ve[i] << ' ';
        }
        for (auto i : ve) {
            cout << i << " ";
        }
        cout << '\n';
    }
}