#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n, l, r;
    while (t--) {
        cin >> n >> l >> r;
        vector<int> ve;
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            if (l % i == 0) {
                ve.push_back(l);
            } else if (l + (i - l % i) <= r) {
                ve.push_back(l + (i - l % i));
            } else {
                cout << "No" << '\n';
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << '\n';
            for (auto i : ve) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
}