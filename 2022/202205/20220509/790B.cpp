#include <algorithm>
#include <iostream>
using namespace std;
int a[60];
int main() {
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        cin >> tmp;
        int sum = 0;
        for (int i = 1; i <= tmp; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a + 1, a + tmp + 1);
        int num = a[1];
        sum -= num * tmp;
        cout << sum << '\n';
    }
}