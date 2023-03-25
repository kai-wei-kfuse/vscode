#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n, m, k;
    while (t--) {
        cin >> n >> m >> k;
        int flag = 1, flag2 = 1, flag_ = 0, flag2_ = 0;
        vector<int> a(k + 1);
        vector<pair<int, int> > ve(k + 1);
        long long summ = 0, sumn = 0;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            if (a[i] / m >= 2)
                summ += a[i] / m;  // n行，每行m个
            if (a[i] / n >= 2)
                sumn += a[i] / n;  // m行，每行n个
            if (a[i] / m >= 3)
                flag_ = 1;
            if (a[i] / n >= 3)
                flag2_ = 1;
        }
        if (summ >= n && (flag_ || n % 2 == 0) ||
            sumn >= m && (flag2_ || m % 2 == 0))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}