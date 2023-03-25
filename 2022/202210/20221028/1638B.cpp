#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> odd, even;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp % 2 == 0) {
                even.push_back(tmp);
            } else {
                odd.push_back(tmp);
            }
        }
        int flag = 0;
        for (int i = 1; i < even.size(); i++) {
            if (even[i] < even[i - 1]) {
                flag = 1;
                break;
            }
        }
        for (int i = 1; i < odd.size(); i++) {
            if (odd[i] < odd[i - 1]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}