#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string a[26];
int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        vector<int> sum(26);
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                for (int l = 0; l < a[j].size(); l++) {
                    sum[a[j][l] - 'a']++;
                }
            }
        }
        int tmp = 0;
        for (auto i : sum) {
            if (i == k)
                tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}