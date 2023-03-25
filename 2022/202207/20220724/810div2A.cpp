#include <iostream>
using namespace std;

int a[100005];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0)
            for (int i = 1; i <= tmp; i++) {
                if (i % 2 == 1) {
                    cout << i + 1 << ' ';
                } else {
                    cout << i - 1 << ' ';
                }
            }
        else if (tmp % 2 == 1 && tmp > 1) {
            for (int i = 1; i <= tmp - 3; i++) {
                if (i % 2 == 1) {
                    cout << i + 1 << ' ';
                } else {
                    cout << i - 1 << ' ';
                }
            }
            if (tmp >= 3)
                cout << tmp - 1 << ' ' << tmp << ' ' << tmp - 2;
        } else if (tmp == 1) {
            cout << '1';
        }
        cout << '\n';
    }
}
