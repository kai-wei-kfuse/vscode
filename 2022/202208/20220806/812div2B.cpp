#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int flag = 0, cnt = 0;
        for (int i = 2; i < n; i++) {
            if (ve[i - 1] > ve[i]) {
                cnt = 1;
            }
            if (cnt == 1 && ve[i + 1] > ve[i]) {
                flag = 1;
            }
        }
        if (flag == 1) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
}