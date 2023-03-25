#include <cstring>
#include <iostream>
using namespace std;
char a[55][55];
int b[55][55];
int main() {
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= y; i++) {
            int last = x;
            for (int j = x; j >= 1; j--) {
                if (a[j][i] == 'o')
                    last = j - 1;
                if (a[j][i] == '*') {
                    swap(a[j][i], a[last][i]);
                    last--;
                }
            }
        }
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}