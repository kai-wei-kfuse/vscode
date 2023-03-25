#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h, m;
        pair<int, int> time, x = {24, 60};
        cin >> n >> time.first >> time.second;
        vector<pair<int, int> > ans(n), tmp(n);
        for (int i = 0; i < n; i++) {
            cin >> tmp[i].first >> tmp[i].second;
            // if (tmp[i].first - time.first < 0) {
            //     ans[i].first = x.first - time.first + tmp[i].first;
            //     ans[i].second = x.second - time.second + tmp[i].second;
            //     if (ans[i].second >= 60) {
            //         ans[i].second %= 60;
            //         ans[i].first++;
            //     }
            //     ans[i].first--;
            // } else if (tmp[i].first - time.first > 0) {
            //     ans[i].first = tmp[i].first - time.first;
            //     if (tmp[i].second - time.second > 0)
            //         ans[i].second = tmp[i].second - time.second;
            //     else {
            //         ans[i].second = x.second - time.second+tmp[i].second;
            //         ans[i].first--;
            //     }
            // } else {
            //     ans[i].first = 0;
            //     if (tmp[i].second - time.second > 0)
            //         ans[i].second = tmp[i].second - time.second;
            //     else if (tmp[i].second - time.second < 0) {
            //         ans[i].first = x.first - time.first + tmp[i].first;
            //         ans[i].second = x.second - time.second + tmp[i].second;
            //         if (ans[i].second >= 60) {
            //             ans[i].second %= 60;
            //             ans[i].first++;
            //         }
            //         ans[i].first--;
            //     } else {
            //         ans[i].second = 0;
            //     }
            // }
            ans[i].first = tmp[i].first - time.first;
            ans[i].second = tmp[i].second - time.second;
            if (ans[i].first < 0) {
                ans[i].first += x.first;
            }
            if (ans[i].second < 0 && ans[i].first > 0) {
                ans[i].second = x.second - time.second + tmp[i].second;
                ans[i].first--;
            }
            if (ans[i].first == 0 && ans[i].second < 0) {
                ans[i].first += x.first - 1;
                ans[i].second = x.second - time.second + tmp[i].second;
            }
            // cout << ans[i].first << ' ' << ans[i].second << endl;
        }
        // cout << endl;
        sort(ans.begin(), ans.end());
        cout << ans[0].first << ' ' << ans[0].second << '\n';
    }
}