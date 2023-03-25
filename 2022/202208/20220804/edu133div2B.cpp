#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        for (int i = n; i >= 2; i--) {
            cout << n << ' ';
            for (int j = 2, k = 2; j <= n; j++) {
                if (j != i) {
                    cout << k << ' ';
                    k++;
                } else if (i == j) {
                    cout << '1' << ' ';
                }
            }
            cout << '\n';
        }
    }
}