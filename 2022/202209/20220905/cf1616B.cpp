#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        int idx = 0;
        if (s[0] <= s[1]) {
            cout << s[0] << s[0];
        } else {
            for (int i = 1; i < n; i++) {
                if (s[i] <= s[i - 1]) {
                    idx = i;
                } else{
                    break;
                }
            }
            for (int i = 0; i <= idx; i++) {
                cout << s[i];
            }
            for (int i = idx; i >= 0; i--) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}