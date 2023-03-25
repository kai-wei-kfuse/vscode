#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int tmp;
    string s;
    while (n--) {
        cin >> tmp;
        cin >> s;
        int len = s.length();
        int sum0 = 0, sum1 = 0, cnt = 0, sum = 0, flag = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                sum0++;
            }
            if (s[i] == '1') {
                sum1++;
            }
            // cout << sum0 << ' ' << sum1 << '\n';
            if (sum0 > 0 && sum1 > 0) {
                if (s[i] == '1') {
                    if (sum0 % 2 == 1) {
                        if (flag) {
                            sum += cnt;
                            cnt = 0;
                            flag = 0;
                        } else
                            flag = 1;
                    }
                    if (flag)
                        cnt++;
                    sum0 = 0;
                }
                if (s[i] == '0') {
                    if (sum1 % 2 == 1) {
                        if (flag) {
                            sum += cnt;
                            cnt = 0;
                            flag = 0;
                        } else
                            flag = 1;
                    }
                    if (flag)
                        cnt++;
                    sum1 = 0;
                }
            }
            // cout << cnt << '\n';
        }
        if (flag)
            sum += cnt;
        cout << sum << '\n';
    }
}