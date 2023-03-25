#include <algorithm>
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
        int num = 1;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                sum0++;
            }
            if (s[i] == '1') {
                sum1++;
            }
            // cout << sum0 << ' ' << sum1 << '\n';
            if (sum0 > 0 && sum1 > 0) {
                num++;
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
        cout << sum << ' ';
        // cout << num << endl;
        for (int i = 1; i < len; i += 2) {
            if (s[i - 1] != s[i]) {
                s[i - 1] = s[i] = '3';
            }
        }
        // for (int i = 0; i < len; i++) {
        //     cout << s[i];
        // }
        // cout << endl;
        int l = 3, r = 3, le, re;
        for (int i = 1; i < len; i++) {
            if (s[i] == '3' && i != 1 && l == 3) {
                l = s[i - 1] - '0';
                le = i;
            }
            if (s[i] == '3' && i == 1) {
                l = 4;
                le = 0;
            }
            if (s[i] != '3' && s[i - 1] == '3' && r == 3) {
                r = s[i] - '0';
                re = i;
            }
            if (s[i] == '3' && i == len - 1) {
                r = 4;
                re = len - 1;
            }
            if (l != 3 && r != 3) {
                // cout << l << ' ' << r << endl;
                // cout << le << ' ' << re << endl;
                for (int j = le; j <= re; j++) {
                    if (l != 4)
                        s[j] = (char)(l + '0');
                    else if (r != 4)
                        s[j] = (char)(r + '0');
                    else
                        s[j] = '1';
                }
                l = 3;
                r = 3;
            }
        }
        // cout << endl;
        // for (int i = 0; i < len; i++) {
        //     cout << s[i];
        // }
        // cout << endl;
        int sums = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] != s[i - 1])
                sums++;
        }
        cout << sums << '\n';
    }
}