#include <bits/stdc++.h>
using namespace std;

struct xx {
    int x, y, h, id,is;
    //bool operator<(const xx& a) const { return id < a.id; }
};
int dist(int a1, int b1, int a2, int b2) {
    return (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2);
}

int main() {
    int n;
    cin >> n;
    set<xx> se;
    int tmp, cnt = 1;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        int x, y;
        cin >> x >> y;
        if (tmp == 1) {
            int h;
            cin >> h;
           // se.insert({x, y, h, cnt});
            cnt++;
            cout << "NO" << endl;
        } else {
            int atk, r;
            cin >> atk >> r;
            int mind = INT_MAX;
            int k, x_, y_;
            for (auto i : se) {
                if (dist(x, y, i.x, i.y) < mind) {
                    k = i.id;
                    x_ = i.x;
                    y_ = i.y;
                    mind = dist(x, y, i.x, i.y);
                }
            }
            cout << x_ << ' ' << y_ << ' ' << k << ' ' << mind << endl;
            int flag = 0;
            for (auto i : se) {
                if (dist(x_, y_, i.x, i.y) <= r * r) {
                    xx tmp = i;
                    tmp.h -= atk * 3;
                    se.erase(i);
                    cout << tmp.h << endl;
                    if (tmp.h > 0) {
                        se.insert(tmp);
                        flag = 1;
                    }
                }
            }
            //cout << se.size() << endl;
            if (flag) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
}