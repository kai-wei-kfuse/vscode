#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
int c[20][20];
int main() {
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        ll ans = 0;
        cin >> tmp;
        string s;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= tmp; i++) {
            cin >> s;
            int x = s[0] - 'a', y = s[1] - 'a';
            for (int i = 0; i < 11; i++)
                ans += c[x][i] + c[i][y];
            ans -= 2 * c[x][y];
            c[x][y]++;
        }
        cout << ans << endl;
    }
}