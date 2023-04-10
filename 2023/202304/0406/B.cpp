#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int n;
vector<int> a(10), b(10);
void dfs(int m) {
    if (m == 1) {
        return;
    }
    for (int i = 1; i <= m; i++) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        dfs(m - 1);
        int tmp = a[m - 1];
        a[m - 1] = a[m];
        a[m] = tmp;
    }
}

int main() {
    cin >> n;
    b[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        b[i] = i;
    }
    dfs(n);
}