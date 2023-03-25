#include <iostream>
typedef long long ll;
using namespace std;
int a[100005];
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll sum = 0;
        int n, k, tmp;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        ll num = sum;
        sum += k;
        for (int i = 1; i <= n; i++) {
            printf("%.8lf ", (double)sum * (double)a[i] / (double)num);
        }
        printf("\n");
    }
}