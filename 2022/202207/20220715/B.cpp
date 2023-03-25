#include <iostream>
using namespace std;
typedef long long ll;
ll a[200005];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        ll ans = 0;
        int intflag = 0;
        ll sum = 0;
        for (int i = 1; i <= tmp; i++) {
            cin >> a[i];
            if (a[i] != 0 && intflag == 0)
                intflag = 1;
            if (intflag && i != tmp) {
                if (a[i] == 0) {
                    ans++;
                }
                sum += a[i];
            }
        }
        // cout << ans << ' ' << sum << endl;
        cout << sum + ans << '\n';
    }
}
/*
2 0 0 0 0
1 1 0 0 0
0 1 1 0 0
0 0 1 1 0
0 0 0 1 1
0 0 0 0 2

2 0 0 2 0 0 0
1 1 0 2 0 0 0
0 1 1 2 0 0 0
0 1 1 1 1 0 0
0 0 1 1 1 1 0
0 0 0 1 1 1 1
0 0 0 0 1 1 2
0 0 0 0 0 1 3
0 0 0 0 0 0 4
*/