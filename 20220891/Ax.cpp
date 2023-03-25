// #include <algorithm>
// #include <iostream>
// using namespace std;

// typedef long long ll;

// int main() {
//     int tt;
//     cin >> tt;
//     while (tt--) {
//         ll n, x, t;
//         cin >> n >> x >> t;
//         if ((n * 2 - 2) * t >= x) {
//             cout << n * 2 * t * 2 << '\n';
//         } else {
//             if (x - (2 * n - 2) * t > t)
//                 cout << min(n * 2 * t + max(x - (n * 2 * t), 0LL) + n * 2 *
//                 t,
//                             2 * t + x + 2 * t * n)
//                      << '\n';
//             else {
//                 cout << n * 2 * t + x - (2 * n - 2) * t + n * 2 * t << '\n';
//             }
//         }
//     }
//     return 0;
// }
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, x, t;
        cin >> n >> x >> t;
        if ((n * 2 - 2) * t >= x) {
            cout << n * 2 * t * 2 << '\n';
        } else {
            // if (x - (2 * n - 2) * t > t)
            cout << min(n * 2 * t + t + max(x - (n * 2 * t), 0LL) + n * 2 * t,
                        n * 2LL * t + max(x - (2 * n - 2LL) * t, 0LL) +
                            n * 2 * t)
                 << '\n';
            // else {
            //     cout << n * 2 * t + x - (2 * n - 2) * t + n * 2 * t << '\n';
            // }
        }
    }
    return 0;
}