#include <algorithm>
#include <iostream>
using namespace std;
struct xx {
    int max, min;
} b[200005];
int a[200005];
int main() {
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        int flag = 0;
        cin >> tmp;
        int cnt = 0;
        if (tmp % 2 == 0) {
            for (int i = 1; i <= tmp; i++) {
                cin >> a[i];
                if (i % 2 == 0) {
                    b[++cnt].max = max(a[i], a[i - 1]);
                    b[cnt].min = min(a[i], a[i - 1]);
                }
            }
            for (int i = 2; i <= cnt; i++) {
                if (b[i].min < b[i - 1].max) {
                    flag = 1;
                }
            }
        } else {
            cin >> a[1];
            b[++cnt].max = a[1];
            for (int i = 2; i <= tmp; i++) {
                cin >> a[i];
                if (i % 2 == 1) {
                    b[++cnt].max = max(a[i], a[i - 1]);
                    b[cnt].min = min(a[i], a[i - 1]);
                }
            }
            for (int i = 2; i <= cnt; i++) {
                if (b[i].min < b[i - 1].max) {
                    flag = 1;
                }
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}