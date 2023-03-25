#include <cstring>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        int len = a.length();
        int flag = 0;
        for (int i = 0; i < len; i++) {
            if ((a[i] == 'a' || a[i] == 'A') && i > 0) {
                flag = 1;
            }
            if ((a[i] == 'z' || a[i] == 'Z') && i < len - 1) {
                flag = 1;
            }
            cout << a[i] << ' ' << a[i + 1] << endl;
            if (a[i] >= 'a' && a[i] <= 'z') {
                if ((a[i + 1] >= 'A' && a[i + 1] <= 'Z') ||
                    tolower(a[i + 1]) == a[i]) {
                    continue;
                } else if (a[i + 1] + 1 == a[i] &&
                           (a[i + 1] >= 'a' && a[i + 1] <= 'z')) {
                    continue;
                } else
                    flag = 1;
            }
            if (a[i] >= 'A' && a[i] <= 'Z') {
                cout << toupper(a[i + 1]) - 1 << ' ' << (int)a[i] << endl;
                if ((a[i + 1] >= 'a' && a[i + 1] <= 'z') ||
                    a[i + 1] == toupper(a[i])) {
                    continue;
                } else if (toupper(a[i + 1]) - 1 == a[i] &&
                           (a[i + 1] >= 'A' && a[i + 1] <= 'Z')) {
                    continue;
                } else
                    flag = 1;
            }
        }
        if (flag)
            cout << "N" << endl;
        else
            cout << "Y" << endl;
    }
}