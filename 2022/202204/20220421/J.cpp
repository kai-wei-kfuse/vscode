#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;
#define N 100005
int t, cnt;
ll sum = 0;
int a[N], in[N], f[N];
vector<int> edge[N];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        // scanf("%d", &t);
        cin >> t;
        for (int i = 1; i <= t; i++) {
            // scanf("%d", &a[i]);
            cin >> a[i];
            sum += a[i];
        }
        a[0] = a[t + 1] = 1e9 + 1;
        for (int i = 2; i <= t; i++) {
            if (a[i] > a[i - 1]) {  // a[i-1]->a[i]
                // cout << a[i] << ' ' << a[i - 1] << ' ';
                edge[i - 1].push_back(i);
                in[i]++;
            }
            if (a[i] < a[i - 1]) {  // a[i]->a[i-1]
                // cout << a[i] << ' ' << a[i - 1] << ' ';
                edge[i].push_back(i - 1);
                in[i - 1]++;
            }
        }
        //---------------------------------------
        queue<int> Q;
        for (int i = 1; i <= t; i++) {
            if (in[i] == 0) {
                Q.push(i);
            }
        }
        while (!Q.empty()) {
            int top = Q.front();
            Q.pop();
            for (int i = 0; i < edge[top].size(); i++) {
                int now = edge[top][i];
                f[now] = max(f[now], f[top] + 1);
                if (--in[now] == 0) {
                    Q.push(now);
                }
            }
        }
        //-------------------------------
        for (int i = 1; i <= t; i++) {
            sum -= f[i];
        }
        cnt++;
        if (sum % 2 == 1) {
            // printf("Case %d: Alice\n", cnt);
            cout << "Case " << cnt << ": "
                 << "Alice" << '\n';
        } else {
            // printf("Case %d: Bob\n", cnt);
            cout << "Case " << cnt << ": "
                 << "Bob" << '\n';
        }
        for (int i = 1; i <= t; i++) {
            edge[i].clear();
            f[i] = 0;
            in[i] = 0;
        }
        sum = 0;
    }
}