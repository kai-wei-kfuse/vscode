#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string a, b;
    while (n--) {
        cin >> a;
        cin >> b;
        if (b.length() == 1 && b[0] == 'a') {
            cout << '1' << endl;
        } else {
            int len = b.length();
            int numa = 0;
            for (int i = 0; i < len; i++) {
                if (b[i] == 'a') {
                    numa++;
                }
            }
            if (numa > 0) {
                cout << "-1" << endl;
            } else {
                long long lena = a.length();
                cout << (1LL << lena) << endl;
            }
        }
    }
}