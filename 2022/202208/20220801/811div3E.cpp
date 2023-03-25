#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        int flag5 = 0, flag = 0;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            if (flag5 == 0 && (ve[i] % 10 == 5 || ve[i] % 10 == 0))
                flag5 = 1;
            while (ve[i] % 10 != 8 && ve[i] % 10 != 0)
                ve[i] += ve[i] % 10;
        }
        if (flag == 0) {
            sort(ve.begin() + 1, ve.end());
            for (int i = 2; i <= n; i++) {
                if ((ve[i] - ve[i - 1]) % 20 != 0) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag5) {
            for (int i = 2; i <= n; i++) {
                if (ve[i] != ve[i - 1]) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}