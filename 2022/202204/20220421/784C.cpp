#include <iostream>
using namespace std;
int odd[1003], even[1003];
int main() {
    int n;
    cin >> n;
    int t;
    while (n--) {
        cin >> t;
        int odds = 1, evens = 1;
        int flago = 0, flage = 0, flago2 = 0, flage2 = 0;
        for (int i = 1; i <= t; i++) {
            if (i % 2 == 1) {
                cin >> odd[odds];
                if (odd[odds] % 2 == 1) {
                    flago++;
                } else {
                    flage++;
                }
                odds++;
            } else {
                cin >> even[evens];
                if (even[evens] % 2 == 1) {
                    flago2++;
                } else {
                    flage2++;
                }
                evens++;
            }
        }
        // cout << flago << ' ' << flage << endl;
        // cout << flago2 << ' ' << flage2 << endl;
        // cout << t / 2 << ' ' << t / 2 + 1 << endl;
        if (t % 2 == 0) {
            if ((flago == t / 2 || flage == t / 2) &&
                (flago2 == t / 2 || flage2 == t / 2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if ((flago == t / 2 + 1 || flage == t / 2 + 1) &&
                (flago2 == t / 2 || flage2 == t / 2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}