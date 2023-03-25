#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct xx {
    int v, i;
} a[100005];
int in[100005];
vector<int> ve[100005];

bool cmp(xx a, xx b) {
    return a.v > b.v;
}

int main() {
    int t;
    cin >> t;
    int n, m;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].v;
            a[i].i = i;
        }
        sort(a + 1, a + n + 1, cmp);
        int x, y;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            ve[x].push_back(y);
            ve[y].push_back(x);
            in[x]++;
            in[y]++;
        }
        if (m % 2 == 0) {
            cout << '0' << '\n';
        } else {
            int sad = 0;
            for (int i = 1; i <= n; i++) {
                for (auto j : ve[a[i].i]) {
                                }
            }
            cout << sad << '\n';
        }
    }
}