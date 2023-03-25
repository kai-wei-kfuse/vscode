#include <iostream>
using namespace std;
int a[105];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        for (int i = 1; i <= tmp; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= tmp; i++) {
            int move;
            cin >> move;
            char c;
            for (int j = 1; j <= move; j++) {
                cin >> c;
                if (c == 'U') {
                    if (a[i])
                        a[i]--;
                    else
                        a[i] = 9;
                }
                if (c == 'D') {
                    a[i]++;
                    a[i] %= 10;
                }
            }
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}