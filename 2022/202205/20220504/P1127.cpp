#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int st_, end_, set_, cnt;
int in[27], out[27], vis[27], parent[27], vis2[27];

string s[27], ans[27];
vector<int> mp[30];
int n, tot;
int over() {
    cout << "***";
    return 0;
}
int find(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void root(int x, int y) {
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_)
        parent[x] = y;
}
int chack() {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 1; i <= 26; i++) {
        if (vis[i] == 1) {
            for (int j = 0; j < mp[i].size(); j++) {
                root(i, mp[i][j]);
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= 26; i++) {
        if (vis[i] > 0) {
            if (parent[i] == i)
                sum++;
        }
    }
    cout << sum << endl;
    if (sum == 1)
        return 1;
    else {
        return 0;
    }
}
void dfs(int x, int num) {
    for (int i = 1; i <= n; i++) {
        if (vis2[i] == 0 && s[i][0] - 'a' == x) {
            vis2[i] = 1;
            dfs(s[i][s[i].length() - 1] - 'a', num + 1);
            ans[++tot] = s[i];
        }
    }
}
int main() {
    int flag = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) {
        st_ = s[i][0] - 'a' + 1;
        end_ = s[i][s[i].size() - 1] - 'a' + 1;
        vis[st_] = 1;
        in[end_]++;
        out[st_]++;
        mp[st_].push_back(end_);
    }
    for (int i = 1; i <= 26; i++) {
        cout << char(i - 1 + 'a') << ' ';
    }
    cout << endl;
    for (int i = 1; i <= 26; i++) {
        cout << vis[i] << ' ';
    }
    if (!chack()) {
        cout << 'y';
        over();
        return 0;
    }
    int ins = 0, outs = 0, head;
    for (int i = 1; i <= n; i++) {
        if (vis[i] > 0) {
            if (in[i] - out[i] >= 1)
                ins++;
            if (out[i] - in[i] >= 1)
                outs++;
            if (out[i] - in[i] == 1)
                head = i;
        }
    }
    if (ins > 1 || outs > 1) {
        cout << 'x';
        over();
        return 0;
    }
    if (ins == 1 && outs == 1) {
        dfs(head, 0);
    } else if (ins == 0 && outs == 0) {
        for (int i = 1; i <= n; i++) {
            if (vis[i] > 0)
                dfs(i, 0);
        }
    }
    for (int i = tot; i >= 1; i--) {
        cout << ans[i];
        if (i > 1)
            cout << '.';
    }
}