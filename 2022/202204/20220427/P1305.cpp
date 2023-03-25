#include <cstring>
#include <iostream>
using namespace std;
int vis[27];
struct node {
    int r, l;
} nod[30];
void dfs(int x) {
    cout << char(x + 'a' - 1);
    if (nod[x].l != -1)
        dfs(nod[x].l);
    if (nod[x].r != -1)
        dfs(nod[x].r);
}
int main() {
    int n;
    cin >> n;
    string a;
    while (n--) {
        cin >> a;
        int x = a[0] - 'a' + 1;
        vis[x]++;
        // cout << char(x + 'a' - 1) << endl;
        if (a[1] != '*') {
            nod[x].l = a[1] - 'a' + 1;
            vis[nod[x].l]++;
        } else
            nod[x].l = -1;
        if (a[2] != '*') {
            nod[x].r = a[2] - 'a' + 1;
            vis[nod[x].r]++;
        } else
            nod[x].r = -1;
        // cout << nod[x].l << ' ' << nod[x].r << endl;
    }
    int root;
    for (int i = 1; i <= 26; i++) {
        if (vis[i] == 1) {
            root = i;
            break;
        }
    }
    dfs(root);
}