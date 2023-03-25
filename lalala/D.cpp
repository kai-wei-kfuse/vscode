#include <iostream>
using namespace std;
int a[10005];
int main() {
    int n;
    cin >> n;
    // cout << n / 2 + n % 2 << endl;
    for (int i = 1; i <= n / 2 + n % 2; i++) {
        a[i] = 2 * (n - i);
    }
    if (n % 2 != 0)
        for (int i = n / 2 + 1, j = n / 2 + 1; i <= n; i++, j--) {
            a[i] = a[j];
        }
    else
        for (int i = n / 2 + 1, j = n / 2; i <= n; i++, j--) {
            a[i] = a[j];
        }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}