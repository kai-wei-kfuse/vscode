#include <algorithm>
#include <iostream>
using namespace std;
int a[200005];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        cin >> tmp;
        for (int i = 1; i <= tmp; i++) {
            cin >> a[i];
        }
        int i = 0, j = tmp + 1;
        int suma = 0, sumb = 0, ans = 0, res = 0;
        while (i < j) {
            if (suma == sumb) {
                // cout << suma << ' ' << sumb << endl;
                ans = max(ans, res);
                i++, j--;
                suma += a[i];
                sumb += a[j];

                res += 2;
            } else if (suma > sumb) {
                j--;
                sumb += a[j];
                // cout << sumb << endl;

                res++;
            } else if (suma < sumb) {
                i++;
                suma += a[i];

                res++;
            }
        }
        cout << ans << endl;
    }
}