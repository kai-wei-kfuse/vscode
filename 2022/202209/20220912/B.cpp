#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int len = s.length();
        int tmp;
        string ans = "";
        for (int j = len - 1; j >= 0; ) {
                if (s[j] == '0') {
                    tmp = (s[j-2 ] - '0') * 10 + s[j-1] - '0';
                   // cout << tmp << endl;
                    ans += char(tmp + 'a' - 1);
                    j -= 3;

                } else {
                    tmp = (s[j] - '0');
                    ans += char(tmp + 'a' - 1);
                     j--;
                }
            
        }
        // if (s[len - 2] != '0' && s[len - 1] != '0') {
        //     ans += char(s[len - 2] - '0' + 'a' - 1);
        // }
        // if (s[len - 1] != '0') {
        //     ans += char(s[len - 1] - '0' + 'a' - 1);
        // }
        for (int i = ans.length()-1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
}
