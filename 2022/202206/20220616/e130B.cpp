#include <algorithm>
#include <iostream>
using namespace std;
int a[200005];
long long s[200005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << s[a] - s[a - b] << '\n';
    }
}