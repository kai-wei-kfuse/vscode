#include <iostream>
using namespace std;
typedef unsigned long long ull;

const int P = 131;
char a[100005];
ull h[100005], p[100005];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, m;
    cin >> n >> m >> a + 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + a[i];
    }
    for (int i = 1; i <= m; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
}