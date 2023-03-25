#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.length();
        if (len == 2) {
            cout << s[1] << '\n';
        } else {
            int minn = 0x3f3f3f3f, idx = 0;
            for (int i = 0; i < len; i++) {
                // if ((len - 1 - i) % 2 == 0) {
                //  cout << s[i] - '0' << ' ';
                // if (s[i] - '0' <= minn)
                minn = min(minn, s[i] - '0');
            }
            cout << minn << '\n';
        }
    }
}