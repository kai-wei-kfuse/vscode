#include <iostream>
typedef long long ll;
using namespace std;
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = 1, y = 1;
    ll sum = 0;
    ll day = 0;
    while (1) {
        if (x <= 5) {
            sum += a;
            x++;
            day++;
            if (sum >= c)
                break;
        }
        if (x == 6 && y <= 2) {
            sum += b;
            y++;
            day++;
            if (sum >= c)
                break;
        }
        if (x == 6 && y == 3) {
            x = 1, y = 1;
        }
    }
    cout << day;
    return 0;
}