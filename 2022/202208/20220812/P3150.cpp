#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x % 2 == 1) {
            cout << "zs wins" << '\n';
        } else {
            cout << "pb wins" << '\n';
        }
    }
}