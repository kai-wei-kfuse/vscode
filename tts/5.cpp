#include <iostream>
using namespace std;
int a[7];
int vis[10][10];
int main() {
    int tmp;
    for (int i = 1; i <= 6; i++) {
        cin >> a[i];
        vis[i][a[i]] = 1;
    }
    cin >> tmp;
    for (int j = 1; j <= tmp; j++) {
        for (int i = 1; i <= 6; i++) {
            for (int k = 6; k >= 1; k--) {
                if (vis[i][k] == 0) {
                    a[i] = k;
                    vis[i][k] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= 6; i++) {
        cout << a[i];
        if (i < 6)
            cout << ' ';
    }
}