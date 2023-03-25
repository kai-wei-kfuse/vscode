#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a[500];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int tmp, x;
        cin >> tmp >> x;
        for (int i = 1; i <= 2 * tmp; i++) {
            cin >> a[i];
            // ve.push_back(tmp);
        }
        int flag = 0;
        // sort(ve.begin(), ve.end());
        sort(a + 1, a + 2 * tmp + 1);
        for (int i = tmp + 1; i <= 2 * tmp; i++) {
            if (a[i] - a[i - tmp] < x) {
                cout << "NO";
                if (n > 0)
                    cout << '\n';
                // cout << ve[i] << ' ' << ve[i - a] << '\n';
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "YES";
            if (n > 0)
                cout << '\n';
        }
    }
}