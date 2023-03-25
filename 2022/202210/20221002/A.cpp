#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n -= 3;
        if (n == 2)
            cout << 0 << endl;
        else
            cout << n / 3 - 1 << endl;
    }
}  //