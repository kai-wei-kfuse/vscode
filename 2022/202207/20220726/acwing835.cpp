#include <iostream>
using namespace std;
const int N = 1e5 + 7;

int son[N][26], idx, cnt[N];
char s[N];

void insert(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    char tmp;
    while (n--) {
        cin >> tmp;
        cin >> s;
        if (tmp == 'I') {
            insert(s);
        } else if (tmp == 'Q') {
            cout << query(s) << '\n';
        }
    }
}