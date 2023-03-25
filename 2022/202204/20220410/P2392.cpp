#include <algorithm>
#include <iostream>
using namespace std;
int a[5];
int x[5][22], sum = 0, ans = 0, lefts, rights;

void dfs(int t, int i) {
    // cout << lefts << ' ' << rights << endl;
    if (t > a[i]) {
        sum = min(sum, max(lefts, rights));
        return;
    }
    lefts += x[i][t];
    // cout << lefts << ' ' << x[i][t] << endl;
    dfs(t + 1, i);
    lefts -= x[i][t];
    // cout << lefts << endl;
    rights += x[i][t];
    dfs(t + 1, i);
    rights -= x[i][t];
}

int main() {
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= a[i]; j++) {
            cin >> x[i][j];
        }
        lefts = 0, rights = 0, sum = 0x3f3f3f;
        dfs(1, i);
        // cout << rights << ' ' << lefts << endl;
        ans += sum;
    }
    cout << ans;
}