#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 10010, s = 55, M = 1000010;
int tr[N * s][26], cnt[N * s], idx;
char str[M];
int next_[N * s];

void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int t = str[i] - 'a';
        if (!tr[p][t])
            tr[p][t] = ++idx;
        p = tr[p][t];
    }
    cnt[p]++;
}

void build() {
    queue<int> Q;
    for (int i = 0; i < 26; i++) {
        if (tr[0][i])
            Q.push(tr[0][i]);
    }
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++) {
            int p = tr[t][i];
            if (!p)
                tr[t][i] = tr[next_[t]][i];
            else {
                next_[p] = tr[next_[t]][i];
                Q.push(p);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(next_, 0, sizeof next_);
        idx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> str;
            insert();
        }
        int res = 0;
        cin >> str;
        build();
        for (int i = 0, j = 0; str[i]; i++) {
            int t = str[i] - 'a';
            j = tr[j][t];
            int p = j;
            while (p) {
                res += cnt[p];
                cnt[p] = 0;
                p = next_[p];
            }
        }
        cout << res << '\n';
    }
}