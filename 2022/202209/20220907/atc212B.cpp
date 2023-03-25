#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int flags = 0, flag2 = 0;
    for (int i = 1; i < 4; i++) {
        if (s[i] != s[i - 1]) {
            flags = 1;
        }
        if ((s[i - 1] - '0' + 1) % 10 != (s[i] - '0')) {
            flag2 = 1;
        }
    }
    //cout << flags << ' ' << flag2;
    if (flags && flag2) {
        cout << "Strong" << '\n';
    } else {
        cout << "Weak" << '\n';
    }
}