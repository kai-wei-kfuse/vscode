#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        cin >> tmp;
        string a;
        cin >> a;
        int ans = 0;
        int len = a.length();
        int mid = len / 2;
        if (len % 2 == 1)
            ans++;
        int i = 1;
        char rule = a[mid];
        if (len % 2 == 0)
            while (mid - i >= 0) {
                if (a[mid - i] == a[mid + i - 1] && a[mid - i] == rule)
                    ans += 2;
                else
                    break;
                i++;
            }
        else
            while (mid - i >= 0) {
                if (a[mid - i] == a[mid] && a[mid + i] == a[mid] &&
                    a[mid - i] == rule)
                    ans += 2;
                else
                    break;
                i++;
            }
        cout << ans << '\n';
    }
}