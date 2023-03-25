#include <bits/stdc++.h>
using namespace std;
#define int long long
struct xx {
    int x, y, h, id;
    // bool operator<(const xx& a) const { return id < a.id; }
};
int dist(int a1, int b1, int a2, int b2) {
    return (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2);
}

signed main() {
    int n;
    cin >> n;
    vector<xx> ve;
    int tmp;
    vector<int> v(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        int x, y;
        cin >> x >> y;
        if (tmp == 1) {
            int h;
            cin >> h;
            // se.insert({x, y, h, cnt});
            ve.push_back({x, y, h, i});
        } else {
            int atk, r;
            cin >> atk >> r;
            int mind = LONG_LONG_MAX;
            int k, x_, y_;
            for (auto i : ve) {
                if (i.h > 0 && dist(x, y, i.x, i.y) < mind) {
                    x_ = i.x;
                    y_ = i.y;
                    mind = dist(x, y, i.x, i.y);
                }
            }
            for (auto& ii : ve) {
                if (ii.h > 0 && dist(x_, y_, ii.x, ii.y) <= r * r) {
                    ii.h -= atk * 3;
                    if (ii.h > 0) {
                        v[i] = 0;
                    } else {
                        v[ii.id] = 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}