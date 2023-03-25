#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9 + 13;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> x(n), t(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] *= 2;
    }
 
 
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        t[i] *= 2;
    }
 
    int l = -1, r = INF;
    while(r - l > 1) {
        int m = (l + r) / 2;
 
        int mxl = 0, mnr = INF;
        for(int i = 0; i < n; i++) {
            if(t[i] > m) {
                mxl = INF;
                mnr = 0;
                break;
            } else {
                mxl = max(mxl, x[i] - (m - t[i]));
                mnr = min(mnr, x[i] + (m - t[i]));
            }
        }
 
        if(mxl <= mnr)
            r = m;
        else
            l = m;
    }
 
    int mxl = 0, mnr = INF;
    for(int i = 0; i < n; i++) {
        mxl = max(mxl, x[i] - (r - t[i]));
        mnr = min(mnr, x[i] + (r - t[i]));
    }
  
    cout << mxl / 2;
    if(mxl % 2 != 0)
        cout << ".5";
    cout << '\n';
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--)
        solve();
}