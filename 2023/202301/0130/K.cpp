#include <bits/stdc++.h>
using namespace std;

int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    if (a == 1) {
        cin >> l >> r >> x;  // 直接对端点修改
        add(l, x);
        add(r + 1, -x);
    } else {
        cin >> x;
        cout << query(x) + ve[x] << endl;  // 查询前缀和再加上原数组
    }
}