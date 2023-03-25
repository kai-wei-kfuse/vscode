#include <cstring>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int mod = 32768;
int dis[35000];
queue<int> Q;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    memset(dis, 127, sizeof(dis));
    Q.push(0);
    dis[0] = 0;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        set<int> se;
        // cout << x << endl;
        se.insert((x - 1 + mod) % mod);
        if (x % 2 == 0) {
            se.insert((x / 2) % mod);
            se.insert((x + mod) / 2 % mod);
        }
        // cout << dis[x] << endl;
        for (auto ix : se) {
            if (dis[ix] > dis[x] + 1) {
                dis[ix] = dis[x] + 1;
                // cout << dis[ix] << ' ' << ix << endl;
                Q.push(ix);
            }
        }
    }
    int n, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        cout << dis[tmp] << ' ';
    }
}