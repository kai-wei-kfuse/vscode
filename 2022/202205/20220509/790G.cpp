#include <cstring>
#include <iostream>
using namespace std;
struct xx {
    int x, b, w;
};
xx parent[5000];
xx sum[5000];
int num[5000];
int tmp;
int find(int x) {
    while (parent[x].x != x) {
        x = parent[x].x;
    }
    return x;
}
void root(int x, int y) {
    parent[y].w += parent[x].w;
    parent[y].b += parent[x].b;
    sum[y].w += sum[x].w;
    sum[y].b += sum[x].b;
    cout << x << ' ' << y << '\n';
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_) {
        parent[x_].x = y_;
    }
    for (int i = 1; i <= tmp; i++) {
        cout << sum[i].b << ' ';
    }
    cout << endl;
    for (int i = 1; i <= tmp; i++) {
        cout << sum[i].w << ' ';
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;

    while (n--) {
        cin >> tmp;
        string s;
        memset(sum, 0, sizeof(sum));
        memset(parent, 0, sizeof(parent));
        parent[1].x = 1;
        for (int i = 1; i < tmp; i++) {
            parent[i + 1].x = i + 1;
            cin >> num[i];
        }
        cin >> s;
        for (int i = 0; i < tmp; i++) {
            if (s[i] == 'W') {
                parent[i + 1].w++;
                sum[i + 1].w++;
            } else {
                parent[i + 1].b++;
                sum[i + 1].b++;
            }
        }
        // for (int i = 1; i <= tmp; i++) {
        //     cout << parent[i].b << ' ';
        // }
        // cout << endl;
        // for (int i = 1; i <= tmp; i++) {
        //     cout << parent[i].w << ' ';
        // }
        // cout << endl;
        for (int i = 2; i <= tmp; i++) {
            root(i, num[i - 1]);
        }
        int ans = 0;
        for (int i = 1; i <= tmp; i++) {
            if (parent[i].b == parent[i].w) {
                // cout << i << '\n';
                ans++;
            }
        }
        cout << ans << '\n';
        ans = 0;
        for (int i = 1; i <= tmp; i++) {
            if (sum[i].b == sum[i].w) {
                // cout << i << '\n';
                ans++;
            }
        }
        cout << ans << '\n';
    }
}