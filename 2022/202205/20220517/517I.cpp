#include <iostream>
using namespace std;
int a[] = {0, 7, 27, 41, 49, 63, 78, 108};
int main() {
    int n, num, tmp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        int sum = 0;
        for (int i = 1; i <= num; i++) {
            cin >> tmp;
            sum += a[tmp];
        }
        if (sum >= 120) {
            sum -= 50;
        } else if (sum >= 89) {
            sum -= 30;
        } else if (sum >= 69) {
            sum -= 15;
        }
        cout << sum << '\n';
    }
}