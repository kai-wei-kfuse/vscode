#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// #define IOS ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
const int N = 100005;
int idx;
struct xx {
    int son[10];
    bool x;
} tr[N];
int flag;

inline void insert(char s[]) {
    int p = 0;
    int tmp = idx;
    int l = strlen(s) - 1;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - '0';
        if (!tr[p].son[u]) {
            tr[p].son[u] = ++idx;
        } else if (i == l) {
            flag = 1;
        }
        p = tr[p].son[u];
        if (tr[p].x) flag = 1;
    }
    // if (idx == tmp) flag = 1;
    tr[p].x = 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int m;
        scanf("%d", &m);
        memset(tr, 0, sizeof(tr));
        flag = 0;
        idx = 0;
        for (int j = 1; j <= m; j++) {
            char a[15];
            scanf("%s", a);
            if (!flag)
                insert(a);
        }
        if (flag) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}