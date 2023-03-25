#include <iostream>
using namespace std;
int main() {
    string a;
    int n;
    cin >> n;
    while (n--) {
        cin >> a;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < 3; i++) {
            sum1 += a[i] - '0';
        }
        for (int i = 3; i < 6; i++) {
            sum2 += a[i] - '0';
        }
        if (sum1 == sum2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}