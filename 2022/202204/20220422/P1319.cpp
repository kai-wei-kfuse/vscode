#include <iostream>
using namespace std;
int a[50000];
int main() {
    int n;
    cin >> n;
    int sum = 0, flag = 0;
    int x = 1, y = 0, yy = 0;
    int tmp;
    while (sum < n * n) {
        cin >> tmp;
        sum += tmp;
        y += tmp;
        if (flag == 1) {
            for (int i = yy + 1; i <= y; i++) {
                a[i] = 1;
            }
        }
        yy = y;
        flag = (flag == 0) ? 1 : 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[(i - 1) * n + j];
        cout << endl;
    }
    return 0;
}