#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    return 5 * x * x * x + 2 * x * x + 3 * x + 8;
}
int main() {
    vector<int> ve(100);
    for (int i = 1; i <= 20; i++) {
        ve[i] = f(i);
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 20; j >= 2; j--) {
            ve[j] = ve[j] - ve[j - 1];
        }
        for (int j = 1; j <= 20; j++) {
            cout << ve[j] << ' ';
        }
        cout << endl;
    }
}