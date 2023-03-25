#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[300000];
ll minn = 0x3f3f3f;
int main() {
    int n;
    cin >> n;
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) {
        minn = min((a[i] - a[i - 1]), minn);
    }
    if (minn == 0)
        cout << n;
    else
        cout << (a[n] - a[1]) / minn + 1;
}