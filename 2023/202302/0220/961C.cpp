#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int c[4][6];
    vector<vector<char> > a(n + 5, vector<char>(n + 5)),b(n + 5, vector<char>(n + 5));
    for (int _ = 1; _ <= 4; _++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        b = a;
        // 1
        int res1 = 0,res2=0;
       // cout << res << ' ';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i+j)%2) {
                    if(a[i][j]=='0')
                        res1++;
                    if(a[i][j] == '1')
                        res2++;
                } else {
                    if(a[i][j]=='1')
                        res1++;
                    if(a[i][j] == '0')
                        res2++;
                }
            }
        }
        c[1][_] = res1;
        c[2][_] = res2;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 2;i++){
        for (int i2 = 1; i2 <= 2;i2++){
            for (int i3 = 1; i3 <= 2;i3++){
                for (int i4 = 1; i4 <= 2;i4++)
                {
                    if(i+i2+i3+i4==6){
                       // cout << i << ' ' << i2 << ' ' << i3 << ' ' << i4 << endl;
                        ans = min(ans, c[i][1] + c[i2][2] + c[i3][3] + c[i4][4]);
                    }
                }
            }
        }
    }

    cout << ans;
}