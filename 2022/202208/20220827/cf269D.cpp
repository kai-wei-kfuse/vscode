#include <iostream>
using namespace std;

int a[200005], as[200005], b[200005], bs[200005], next_[200005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++) {
        as[i - 1] = a[i] - a[i - 1];
        // cout << as[i - 1] << ' ';
    }  // cout << endl;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 2; i <= m; i++) {
        bs[i - 1] = b[i] - b[i - 1];
        // cout << bs[i - 1] << ' ';
    }
    // cout << endl;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && bs[i] != bs[j + 1])
            j = next_[j];
        if (bs[i] == bs[j + 1])
            j++;
        next_[i] = j;
    }
    int ans = 0;
    for (int i = 1, j = 0; i <= n-1; i++) {
        while (j && as[i] != bs[j + 1])
            j = next_[j];
        // cout << as[i] <<":"<<bs[j+1]<< endl;
        if (as[i] == bs[j + 1])
            j++;
        if (j == m - 1) {
            j = next_[j];
            ans++;
        }
    }
    if (m == 1)
        ans++;
    cout << ans << '\n';
}
/*
13 5
4 5 5 4 3 2 2 2 3 3 2 1 1
3 4 4 3 2
*/