#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int xx, yy, n;
    cin >> xx >> yy >> n;
    vector<int> ve(n + 1), x(n + 1);
    vector<int> ve2(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        ve.push_back(x[i]);
        ve2.push_back(y[i]);
    }
    sort(ve.begin(), ve.end());
    sort(ve2.begin(), ve2.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    ve2.erase(unique(ve2.begin(), ve2.end()), ve2.end());
    for (int i = 1; i <= n; i++) {
        x[i] = lower_bound(ve.begin(), ve.end(), x[i]) - ve.begin() ;
        y[i] = lower_bound(ve2.begin(), ve2.end(), y[i]) - ve2.begin() ;
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] << ' ' << y[i] << '\n';
    }
}