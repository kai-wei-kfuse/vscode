#include <algorithm>
#include <iostream>
using namespace std;
int parent[2000005];
int ans = 0x3f3f3f;
int find(int x, int& cnt) {
    while (parent[x] != x) {
        cnt++;
        x = parent[x];
    }
    cnt++;
    return x;
}
int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        int cnt = 0;
        if (find(tmp, cnt) == i) {
            ans = min(ans, cnt);
        } else {
            parent[i] = tmp;
        }
    }
    cout << ans;
}