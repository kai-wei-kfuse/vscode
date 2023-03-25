#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int tmp;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (i % 2) {
            res ^= tmp;
        }
    }
    if (res)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}