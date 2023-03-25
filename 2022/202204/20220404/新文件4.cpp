/*********************************************************************
        程序名:
        日期: 2022-04-04 16:00
*********************************************************************/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;

void build_tree(ll node, ll l, ll r) {
    if (l == r) {
        cout << node << ' ';
        return;
    }
    ll left_node = node << 1;       // 2*node
    ll right_node = node << 1 | 1;  // 2*node+1
    ll mid = (l + r) >> 1;          //(l+r)/2
    build_tree(left_node, l, mid);
    build_tree(right_node, mid + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    build_tree(1, 1, n);
    return 0;
}
