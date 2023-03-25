#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        char c;
        string x = "";
        for (int i = 1; i <= 3; i++) {
            cin >> c;
            x += toupper(c);
        }
        if (x != "YES") {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}