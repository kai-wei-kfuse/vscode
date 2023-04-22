#include <bits/stdc++.h>
using namespace std;

#define int long long
#define eps 1e-8

struct xx {
    double a;
    int id;
};

bool cmp(xx x, xx y) {
    return x.a < y.a;
}

signed main() {
    int n;
    cin >> n;
    vector<xx> a;
    vector<xx> b;
    vector<xx> c;
    vector<xx> d;
    double minn = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        double tmp;
        cin >> tmp;
        if (tmp > 1) {
            a.push_back({tmp, i});
        } else if (tmp >= 0 && tmp <= 1) {
            d.push_back({tmp, i});
        } else if (tmp < 0 && tmp >= -1) {
            c.push_back({tmp, i});
        } else
            b.push_back({tmp, i});
    }
    if (c.size()) {
        sort(c.begin(), c.end(), cmp);
    }
    if (d.size()) {
        sort(d.begin(), d.end(), cmp);
    }
    if (b.size()) {
        sort(b.begin(), b.end(), cmp);
        if (b.size() % 2 == 1 && c.size()) {
            if (b.back().a * c[0].a - 1 > eps) {
                b.push_back(c[0]);
            } else {
                b.pop_back();
            }
        } else if (b.size() % 2 == 1) {
            b.pop_back();
        }
        for (auto i : b) {
            a.push_back(i);
        }
    }
    if (!b.size() && !a.size()) {
        if (c.size() > 1 && d.size()) {
            if (c[0].a * c[1].a > d.back().a) {
                a.push_back(c[0]);
                a.push_back(c[1]);
            }
        } else if (d.size()) {
            a.push_back(d.back());
        } else if (c.size()) {
            if (c.size() == 1) {
                a.push_back(c[0]);
            } else {
                a.push_back(c[0]);
                a.push_back(c[1]);
            }
        }
    }
    sort(a.begin(), a.end(), [](xx x, xx y) { return x.id < y.id; });
    cout << a.size() << endl;
    for (auto i : a) {
        cout << i.id << " ";
    }
    cout << endl;
}