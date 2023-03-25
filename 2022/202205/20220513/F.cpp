#include <algorithm>
#include <iostream>
using namespace std;
int parent1[100005], parent2[100005];
int vis[100005];
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> parent1[i];
        if (parent1[i]) {
            ans++;
            vis[parent1[i]] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> parent2[i];
        if (parent2[i]) {
            ans++;
            vis[parent2[i]] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int tmp = i;
            while (parent1[tmp] == parent2[tmp] && parent1[tmp] &&
                   parent2[tmp]) {
                ans -= 2;
                tmp = parent1[tmp];
            }
        }
    }
    cout << ans << '\n';
}