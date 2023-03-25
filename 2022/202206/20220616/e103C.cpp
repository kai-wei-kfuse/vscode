#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string a, b;
    while (n--) {
        int tmp;
        cin >> tmp;
        cin >> a >> b;
        int j = 0;
        int na = 0, nb = 0;
        for (int i = 0; i < tmp; i++) {
            if (a[i] == 'b')
                na++;
            if (b[i] == 'b')
                nb++;
        }
        if (na != nb) {
            cout << "NO" << '\n';
            continue;
        }
        int flag = 0;
        for (int i = 0; i < tmp; i++) {
            if (a[i] == 'b')
                continue;
            while (b[j] == 'b')
                j++;
            if (a[i] != b[j] || (a[i] == 'c' && i < j) ||
                (a[i] == 'a' && i > j)) {
                cout << "NO" << '\n';
                flag = 1;
                break;
            }
            j++;
        }
        if (flag == 0)
            cout << "YES" << '\n';
    }
}