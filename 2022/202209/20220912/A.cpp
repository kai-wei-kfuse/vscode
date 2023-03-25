#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (b > c) {
            int x = b - 1;
            int y = a - 1;
            if (y<x) {
                cout << '1' << endl;
            } else if (x<y) {
                cout << '2' << endl;
            } else {
                cout << '3' << endl;
            }
        } else {
            int x = c - b + c - 1;
            int y = a - 1;
            if (y<x) {
                cout << '1' << endl;
            } else if (x<y) {
                cout << '2' << endl;
            } else {
                cout << '3' << endl;
            }
        }
    }
}