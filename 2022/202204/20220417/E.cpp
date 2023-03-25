#include <iostream>
typedef long long ll;
using namespace std;
int chack(ll x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    ll x, y;
    int tmp;
    while (n--) {
        cin >> x;
        tmp = chack(x);
        int flag = 1;
        for (int i = 2; i <= 9; i++) {
            y = x * i;
            if (chack(y) != tmp) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << tmp << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}