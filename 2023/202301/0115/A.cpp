#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    if (2 * b + 1 == a || 2 * b == a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}