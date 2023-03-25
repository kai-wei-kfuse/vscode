#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int a[100000];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int len, t;
    while (n--) {
        cin >> len >> t;
        string s;
        vector<int> f(len, 0);
        cin >> s;
        int tmpt = t;
        for (int i = 0; i < len && tmpt > 0; i++) {
            if (t % 2 == 0) {
                if (s[i] == '0') {
                    f[i] = 1;
                    tmpt--;
                }
            } else if (t % 2 == 1) {
                if (s[i] == '1') {
                    f[i] = 1;
                    tmpt--;
                }
            }
        }
        f[len - 1] += tmpt;
        for (int i = 0; i < len; i++) {
            if (f[i] % 2 == 1) {
                if (t % 2 == 0) {
                    s[i] = (s[i] == '0') ? '1' : '0';
                }
            }
            if (f[i] % 2 == 0) {
                if (t % 2 == 1) {
                    s[i] = (s[i] == '0') ? '1' : '0';
                }
            }
        }
        cout << s << '\n';
        for (auto i : f) {
            cout << i << " ";
        }
        cout << '\n';
    }
}