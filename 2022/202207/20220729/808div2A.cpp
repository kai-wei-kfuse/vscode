#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tmp, first;
        cin >> first;
        int flag = 1;
        for (int i = 1; i < n; i++) {
            cin >> tmp;
            if (tmp % first != 0) {
                cout << "NO" << '\n';
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES" << '\n';
    }
}