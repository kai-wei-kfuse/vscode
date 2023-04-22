#include <bits/stdc++.h>
using namespace std;

#define int long long
#define eps 1e-10

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
    for (int i = 1; i <= n; i++) {
        double tmp;
        cin >> tmp; 
        if (tmp > 1) {
            a.push_back({tmp, i});
        } else if (tmp >= -1 && tmp<= 1) {
            c.push_back({tmp, i});
        } else
            b.push_back({tmp, i});
    }
    sort(b.begin(), b.end(), cmp);
    sort(c.begin(), c.end(), cmp);

    if (b.size()) {
        if (b.size() % 2 == 1 && c.size()) {
            if (b.back().a * c[0].a - 1 > eps) {
                b.push_back(c[0]);
            } else {
                c.push_back(b[0]);
                b.pop_back();
            }
        } else if (b.size() % 2 == 1) {
            b.pop_back();
        }
        for (auto i : b) {
            a.push_back(i);
        }
    }
    sort(c.begin(), c.end(), cmp);
    if (!b.size() && !a.size()) {
        if(c.size()==1){
            a.push_back(c[0]);
        }else{
            if(c[0].a*c[1].a>c.back().a+eps){
                a.push_back(c[0]);
                a.push_back(c[1]);
            }else{
                a.push_back(c.back());
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