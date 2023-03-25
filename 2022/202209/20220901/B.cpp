#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        vector<vector<char > > ve(n+2,vector<char>(n+2));
        // int rr = r % k;
        // if (rr == 0)
        //     rr = k;
        // int cc = c % k;
        // if (cc == 0)
        //     cc = k;
        // int ini = 0;
        // if(rr==cc){
        //     ini = 1;

        // }
        // cout << rr << '|' << cc << '\n';
        // for (int i = 1; i <= n; i++) {
        //     for (int kk = (i + 1) % k; kk >= 0; kk--) {
        //         cout << ".";
        //     }
        //     for (int j = 1; j <= n - (i + 1) % k; j++) {
        //         if (j % k == 1)
        //             cout << "X";
        //         else
        //             cout << ".";
        //     }
        //     cout << '\n';
        // }
        int tmp = r;
        for (int i = c; i <= n;i++){
            while (ve[r][i] != 'X') {
                ve[r][i] = 'X';
                r = (r - k + n - 1) % n + 1;
            }
        r = (r - 1 + n - 1) % n + 1;
        }
        //cout << 'x';
        r = tmp;
        for (int i = c; i >= 1;i--){
             while (ve[r][i] != 'X') {
                ve[r][i] = 'X';
                r = (r - k + n - 1) % n + 1;
            }
        r = (r + 1 + n - 1) % n + 1;
        }
        //cout << 'd';
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                if(ve[i][j]=='X'){
                    cout << 'X';
                }
                else{
                    cout << ".";
                }
            }
            cout << '\n';
        }
    }
}