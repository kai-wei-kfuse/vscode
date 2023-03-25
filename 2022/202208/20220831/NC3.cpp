#include <algorithm>
#include <iostream>
using namespace std;

const int m = 5000005, mm = 21000005;
int n, idx, son[mm][2], a[m], cnt[mm], ans1;

void insert(int x, int id) {
    int p = 0;
    for (int i = 21; ~i; i--) {       //~i等价于i>=0
        int& s = son[p][x >> i & 1];  //&引用
        if (!s)
            s = ++idx;
        p = s;
    }
    cnt[p] = id;
}

int search(int x) {
    int p = 0, res = 0;
    for (int i = 21; ~i; i--) {
        int s = x >> i & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else
            p = son[p][s];
    }
    ans1 = cnt[p];
    return res;
}

int main() {
    cin >> n;
    int res = -1;
    int ri, le, sum = 0, x;
    insert(0, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum ^= x;
        int tmp = search(sum);
        insert(sum, i);
        if (res < tmp) {
            ri = i;
            le = ans1;
            res = tmp;
        }
    }
    cout << res << ' ' << le + 1 << ' ' << ri << '\n';
}
