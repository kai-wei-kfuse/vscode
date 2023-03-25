#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<double> ve;
    for (int i = 1; i <= n; i++) {
        double sum = 0;
        double minn = 101.0, maxn = 0;
        for (int j = 1; j <= k; j++) {
            double tmp;
            cin >> tmp;
            sum += tmp;
            minn = min(minn, tmp);
            maxn = max(maxn, tmp);
            
        }
        ve.push_back(sum - maxn - minn);
    }
    sort(ve.begin(), ve.end(), greater<double>());
    for (int i = m - 1; i >= 0; i--) {
        printf("%.3f", ve[i] / (double)(k - 2));
        if (i != 0) {
            printf(" ");
        }
    }
}