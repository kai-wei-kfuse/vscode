#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int c[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
            scanf("%d", &c[i]);
        ll gs = 1;
        int flag = 0;
        for (int i = 0; i <= n; i++) {
            if (c[i] >= gs) {
                flag = 1;
                break;
            }
            gs -= c[i];
            gs *= 2;
            if (gs > 1000000)
                break;
        }
        if (flag)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
