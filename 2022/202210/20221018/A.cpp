#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    if (n == 0) {
        cout << "Austin";
    } else if (k != 1) {
        cout << "Adrien";
    } else if (k == 1) {
        if (n % 2 == 0) {
            cout << "Austin";
        } else {
            cout << "Adrien";
        }
    }
}