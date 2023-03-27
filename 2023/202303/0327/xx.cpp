#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> ve(10005);

struct xx {
    int son[2];
    int x;
    bool tag;
} tr[N];
int idx;

void insert(vector<int> a, int len) {  //
    int p = 0;
    for (int i = 1; i <= len; i++) {
        int u = a[i];
        if (!tr[p].son[u]) {
            tr[p].son[u] = ++idx;
        }
        p = tr[p].son[u];
        tr[p].x++;
    }
    tr[p].tag = 1;
}

int query(vector<int> a, int len) {  // 查询前缀和
    int ans = 0;
    int p = 0;
    for (int i = 1; i <= len; i++) {
        int u = a[i];
        if (!tr[p].son[u]) {
            break;
        }
        p = tr[p].son[u];
        if (i == len) {
            ans += tr[p].x;
        } else
            ans += tr[p].tag;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 1; j <= tmp; j++) {
            cin >> ve[j];
        }
        insert(ve, tmp);
    }
    for (int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 1; j <= tmp; j++) {
            cin >> ve[j];
        }
        cout << query(ve, tmp) << endl;
    }
}