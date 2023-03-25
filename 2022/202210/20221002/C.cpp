#include <bits/stdc++.h>
using namespace std;

vector<int> parent(26);
int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> vis(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        string ans = "";
        vector<int> vec;
        for (auto i : s) {
            vec.push_back(i - 'a');
        }
        int cnt = 0, flag = 0;
        for (int i = 0; i < n; i++) {
            if (parent[s[i] - 'a'] != s[i] - 'a' || flag == 26) {
                ans += (parent[s[i] - 'a'] + 'a');
            } else {
                int x_rt = find(s[i] - 'a');
                int y_rt = find(cnt);
                if (x_rt != y_rt) {
                    parent[s[i] - 'a'] = cnt;
                    ans += (cnt + 'a');
                    vis[cnt] = 1;
                    flag++;
                    cnt++;
                    cnt %= 26;
                } else if (x_rt == y_rt) {
                    if (flag == 25) {
                        for (int i = 0; i < 26; i++) {
                            if (vis[i] == 0) {
                                parent[s[i] - 'a'] = i;
                                ans += (i + 'a');
                                flag++;
                                break;
                            }
                        }

                    } else if (flag < 25) {
                        cnt = -1;
                        while (x_rt == y_rt) {
                            cnt++;
                            y_rt = find(cnt);
                        }
                        vis[cnt] = 1;
                        parent[s[i] - 'a'] = cnt;
                        ans += (cnt + 'a');
                        flag++;
                        cnt++;
                        cnt %= 26;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}