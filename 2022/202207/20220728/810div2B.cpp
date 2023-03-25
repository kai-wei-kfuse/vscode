#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int a[100005];

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        vector<pair<int, int> > ve(y + 5);
        vector<int> in(x + 5);
        for (int i = 1; i <= x; i++) {
            cin >> a[i];
        }
        int tmp1, tmp2;
        for (int i = 1; i <= y; i++) {
            cin >> tmp1 >> tmp2;
            ve[i] = {tmp1, tmp2};
            in[tmp1]++;
            in[tmp2]++;
        }
        if (y % 2 == 0) {
            cout << "0" << '\n';
        } else if (y % 2 == 1) {
            int ans = 0x3f3f3f;
            for (int i = 1; i <= x; i++) {
                if (in[i] % 2 == 1) {
                    ans = min(ans, a[i]);
                }
            }
            for (int i = 1; i <= y; i++) {
                if (in[ve[i].first] % 2 == 0 && in[ve[i].second] % 2 == 0) {
                    ans = min(ans, a[ve[i].first] + a[ve[i].second]);
                }
            }
            cout << ans << '\n';
        }
    }
}