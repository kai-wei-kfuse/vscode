#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        cout << (a ^ b ^ c) << endl;
        }
}