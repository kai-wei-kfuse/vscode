#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1, 0), p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        for (int i = 1; i <= n; i++) {
            p[i] = ve[i] - ve[i - 1];
        }
        int f = 1, e = 3;
        while (1) {
            while (e <= n) {
                if(p[e]<0){
                    
                }else{
                    e++;
                }
            }
        }
    }
}