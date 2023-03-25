#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    vector<int> q1(n + 1), q2(n + 1);
    int len = 0,ans=0;
    for (int i = 1; i <= n; i++) {
       // cout << a[i].second << ' ';
        int l = 0, r = len;
        while (l < r) {
            int mid = r + l + 1 >> 1;
            if (q1[mid] < a[i].second) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        len = max(len, r + 1);
        q1[r + 1] = a[i].second;
    }
   // cout << endl;
    ans = len;
    len = 0;
    sort(a.begin() + 1, a.end(), cmp);
    for (int i = 1; i <= n; i++) {
       // cout << a[i].first << ' ';
        int l = 0, r = len;
        while (l < r) {
            int mid = r + l + 1 >> 1;
            if (q2[mid] < a[i].first) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        len = max(len, r + 1);
        q2[r + 1] = a[i].first;
    }
   // cout << endl;
    ans = max(len, ans);
    cout << len << endl;
}
