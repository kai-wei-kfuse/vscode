#include <bits/stdc++.h>
using namespace std;
vector<int> ve(125), vis(125);
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int main() {
    int n, k;
    IOS;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        // string s;
        // cin >> s;
        int st, en;
        cin >> st >> en;
        /* if (s[1] == '0') {
            st = s[4] - '0' + (s[3] - '0') * 10;
            if (s[7] == '0') {
                en = s[10] - '0' + (s[9] - '0') * 10;
            } else if (s[7] == '1') {
                en = s[10] - '0' + (s[9] - '0') * 10 + 60;
            } else if (s[7] == '2') {
                en = 120;
            }
        } else if (s[1] == '1') {
            st = s[4] - '0' + (s[3] - '0') * 10 + 60;
            if (s[7] == '1')
                en = s[10] - '0' + (s[9] - '0') * 10 + 60;
            else if (s[7] == '2')
                en = 120;
        } */
        ve[st]++;
        ve[en + 1]--;
        /* cout << st << ' ' << en + 1 << endl; */
    }
    if (ve[0] < k)
        vis[0] = 1;
    for (int i = 1; i <= 120; i++) {
        ve[i] = ve[i - 1] + ve[i];
        /* cout << ve[i] << ' '; */
        if (ve[i] < k) {
            vis[i] = 1;
        } else {
            vis[i] = 0;
        }
    }
    /* cout << endl;
    for (int i = 0; i <= 120; i++) {
        cout << vis[i];
    }
    cout << endl; */
    vector<string> ans;
    int st = -1, en = -1;
    int cnt = 0;
    for (int i = 0; i <= 121; i++) {
        string tmp = "";
        if (vis[i] == 1 && st == -1) {
            st = i;
            en = i;
        }
        if (vis[i] == 1 && st != -1) {
            en = i;
        }
        if (vis[i] == 0 && st != -1 && en != -1) {
            tmp += to_string(st);
            tmp += "-";
            //--------------------------
            tmp += to_string(en);
            st = -1;
            en = -1;
            cnt++;
            ans.push_back(tmp);
        }
    }
    cout << cnt << endl;
    for (auto i : ans) {
        cout << i << endl;
    }
}