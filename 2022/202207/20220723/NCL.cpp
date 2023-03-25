#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    int tmp;
    while (t--) {
        cin >> tmp;
        // cout << floor(sqrt(tmp));
        int maxn = ceil(sqrt(tmp));
        int tmp1;
        if (tmp % 2 == 0) {
            tmp1 = tmp;
        } else {
            tmp1 = tmp - 1;
        }
        for (int i = 2; i <= tmp1; i += 2) {
            cout << i << ' ';
        }
        for (int i = 1; i <= tmp; i += 2) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}