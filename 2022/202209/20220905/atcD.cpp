#include <iostream>
using namespace std;
int main() {
    
        int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = 1, res = 1;
    for (int i = 1; i <= h + w - 2; i++) {
        ans *= i;
    }
    ans/=
    for (int i = 1; i <= a + b - 2; i++) {
        res *= i;
    }
    cout << ans << ' ' << ans - res;
}