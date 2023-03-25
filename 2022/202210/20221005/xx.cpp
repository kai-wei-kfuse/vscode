#include <iostream>
using namespace std;
int main() {
    int s, t;
    cin >> s >> t;
    long long ans = 0;
    for (int i = 0; i <= s; i++) {
        for (int j = i; j <= s; j++) {
            for (int k = j; k <= s; k++) {
                if (i + j + k <= s && i * j * k <= t) {
                    cout << i << ' ' << j << ' ' << k << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans;
}