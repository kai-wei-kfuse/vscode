#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int now = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!now) {
            if (ve[i] == 0) {
                ans++;
            }
            if (ve[i] == 1) {
                now = 1;
            }
            if (ve[i] == 2) {
                now = 2;
            }
        } else if (now) {
            if (ve[i] == 0) {
                now = 0;
                ans++;
            }
            if (ve[i] && ve[i] == now) {
                ans++;
                now = 0;
            }
            if(ve[i]==1&&now==2){
                now = 1;
            }
            if(ve[i]==2&&now==1){
                now = 2;
            }
            if (ve[i] == 3) {
                now = 3 - now;
            }
        }
        //cout << ans << endl;
    }
    cout << ans;
}