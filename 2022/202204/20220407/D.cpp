#include <algorithm>
#include <iostream>
using namespace std;
struct xx {
    int x, c, sum, res, i;
} a[200005];
int n, h, H;
bool cmp(xx a, xx b) {
    if (a.res != b.res)
        return a.res < b.res;
    else
        return a.i < b.i;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> h >> H;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i].c;
        }
        for (int i = 1; i <= n; i++) {
            a[i].i = i;
            a[i].sum = a[i].c + a[i].x;
            if ((a[i].x / H) % 2 == 0) {
                if (a[i].x % H > h)  //如果上升大于h，
                    a[i].res = a[i].sum + H - h + H - a[i].x % H;
                else {  //上升小于h
                    a[i].res = a[i].sum;
                }
            } else {
                if (a[i].x % H > h)  //下降时
                    a[i].res = a[i].sum + a[i].x % H - h;
                else {
                    a[i].res = a[i].sum;
                }
            }
            // cout << a[i].res << endl;
        }
        sort(a + 1, a + n + 1, cmp);
        cout << a[1].i << endl;
    }
}