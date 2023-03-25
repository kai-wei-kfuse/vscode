#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int a[500005];
int main() {
    int n, cnt = 1;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        int flag = 0, mins = 0x3f3f3f;
        for (int i = 1; i <= t; i++) {
            cin >> a[i];
            if (a[i] % 2 == 1) {
                flag++;
            }
            mins = min(mins, a[i]);
        }
        if (flag == 0) {
            printf("Case %d: 0\n", cnt);
            cnt++;
            continue;
        }
        if (flag == t) {
            printf("Case %d: 1\n", cnt);
            cnt++;
            continue;
        }
        int flag2 = 0;
        for (int i = 1; i <= t; i++) {
            if (a[i] % mins != 0) {
                flag2 = 1;
            }
        }
        if (flag2 == 1) {
            printf("Case %d: -1\n", cnt);
            cnt++;
            continue;
        } else {
            printf("Case %d: 0\n", cnt);
            cnt++;
            continue;
        }
    }
}