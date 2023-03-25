#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, p, x, a, b, c;
        cin >> n >> m >> p >> x >> a >> b >> c;
        cout << min(n, m) << '\n';
    }
}