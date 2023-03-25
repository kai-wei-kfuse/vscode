#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int chack(int x) {
    int tmp;
    while (x) {
        tmp = x % 10;
        x /= 10;
        if (tmp == 1 || tmp == 9 || tmp == 2 || tmp == 0)
            return 1;
    }
    return 0;
}
int main() {
    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (chack(i))
            sum += i;
    }
    cout << sum;
}