#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int a[] = {333, 737, 373};
    int cnt = 500;
    int x = 0;
    sort(a, a + 3);
    // for (int i = 0; i < 3; i++) {
    //     a[i + 1] -= a[0];
    // }
    while (cnt--) {
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ';
        cout << a[1] - a[0] << ' ' << a[2] - a[1] << ' ';
        // cout << __gcd(__gcd(__gcd(a[0], a[1]), __gcd(a[1], a[2])),
        //               __gcd(a[0], a[2]));
        cout << __gcd(__gcd(a [0], a[1]), __gcd(a[1], a[2])) << ' ';
        cout << __gcd(a[1] - a[0], a[2] - a[1]);
        a[0] += 1;
        a[1] += 1;
        a[2] += 1;
        cout << endl;
    }
}