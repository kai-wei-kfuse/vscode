#include <iostream>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
struct xx {
    int x, y;
} p1[100005], parent[100005];
int p3[100005], num, vis[100005];
int find(int x) {
    while (parent[x].x != x) {
        x = parent[x].x = parent[parent[x].x].x;
    }
    return x;
}
void root(int x, int y) {
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_) {
        // if (vis[y_])
        //     vis[x_] = vis[y_];
        // else if (vis[x_])
        //     vis[y_] = vis[x_];
        parent[x_].x = y_;
        parent[y_].y += parent[x_].y;
    }
}
int main() {
    IOS;
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        int ans = 0;
        cin >> tmp;
        for (int i = 1; i <= tmp; i++) {
            parent[i].x = i;
            parent[i].y = 1;
            vis[i] = 0;
            cin >> p1[i].x;
        }
        for (int i = 1; i <= tmp; i++) {
            cin >> p1[i].y;
        }
        int num0 = 0;
        for (int i = 1; i <= tmp; i++) {
            cin >> p3[i];
            if (p3[i] == 0)
                num0++;
        }
        if (num0 == 0) {
            cout << "1" << '\n';
            continue;
        }
        for (int i = 1; i <= tmp; i++) {
            root(p1[i].x, p1[i].y);
            if (p3[i] > 0)
                vis[p1[i].x] = vis[p1[i].y] = 1;
        }
        ans = 1;
        for (int i = 1; i <= tmp; i++) {
            if (parent[i].x == i && vis[i] != 1) {
                // cout << parent[i].y << ' ';
                //  cout << vis[i] << '|';
                if (parent[i].y >= 2) {
                    ans *= 2;
                }
            }
        }
        cout << ans << endl;
    }
}