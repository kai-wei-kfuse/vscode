#include <bits/stdc++.h>
using namespace std;

vector<int> dsu(2005);

int find(int x) {
    while (x != dsu[x]) {
        x = dsu[x] = dsu[dsu[x]];
    }
    return x;
}

int root(int x, int y) {
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_) {
        dsu[x_] = y_;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            dsu[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            root(x, y);
        }
        int ans = 0;
        for (int i=1; i <= n;i++){
            if(dsu[i]==i){
                ans++;
            }
        }
        cout << ans << endl;
    }
}