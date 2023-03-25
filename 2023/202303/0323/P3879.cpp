#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int idx;
char a[25];
struct xx {
    set<int> m;
    int son[26];
} tr[N];

void insert(char s[], int x) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!tr[p].son[u]) {
            tr[p].son[u] = ++idx;
        }
        p = tr[p].son[u];
    }
    tr[p].m.insert(x);
}

void query(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!tr[p].son[u])
            return;
        p = tr[p].son[u];
    }
    for (auto i : tr[p].m) {
        cout << i << ' ';
    }
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 1; j <= tmp; j++) {
            cin >> a;
            insert(a, i);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        query(a);
        cout << endl;
    }
}