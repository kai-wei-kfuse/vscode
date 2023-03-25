#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        int len = a.length();
        int suma = 0, sumb = 0;
        if (len == 1) {
            cout << "Bob" << ' ' << a[0] - 'a' + 1 << endl;
        } else if (len % 2 == 1) {
            if (a[0] > a[len - 1]) {
                for (int i = 0; i < len - 1; i++) {
                    suma += (a[i] - 'a' + 1);
                }
                sumb = a[len - 1] - 'a' + 1;
            } else {
                for (int i = 1; i < len; i++) {
                    suma += (a[i] - 'a' + 1);
                }
                sumb = a[0] - 'a' + 1;
            }
            if (suma > sumb)
                cout << "Alice" << ' ' << suma - sumb << endl;
            else
                cout << "Bob" << ' ' << sumb - suma << endl;
        } else if (len % 2 == 0) {
            for (int i = 0; i < len; i++) {
                suma += (a[i] - 'a' + 1);
            }
            cout << "Alice" << ' ' << suma - sumb << endl;
        }
    }
}