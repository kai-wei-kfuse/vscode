#include <bits/stdc++.h>
using namespace std;

#define int long long
struct xx {
    int num, x, id;
};
bool cmp(xx a, xx b) {
    if (a.num == b.num) {
        if (a.x == b.x) {
            return a.id < b.id;
        } else {
            return a.x > b.x;
        }
    } else {
        return a.num > b.num;
    }
}

signed main() {
    int n;
    cin >> n;
    vector<xx> ve(n + 1, {0, 0, 0});
    for (int i = 1; i <= n; i++) {
        ve[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        int x, sum = 0;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int id, m;
            cin >> id >> m;
            sum += m;
            ve[id].num += m;
            ve[id].x++;
        }
        ve[i].num -= sum;
    }
    sort(ve.begin() + 1, ve.end(), cmp);
    // int len = ve.size();
    for (int i = 1; i <= n; i++) {
        cout << ve[i].id << ' ';
        if (ve[i].num == 0) {
            cout << "0.00" << endl;
        } else {
            double x = ve[i].num;
            printf("%.2f\n",x / 100);
            // cout << ve[i].num / 100 << ".";
            // if (ve[i].num < 0) {
            //     if((-ve[i].num % 100)<10)
            //     cout << "0"<< (-ve[i].num % 100) << endl;
            //     else{
            //         cout <<(-ve[i].num % 100) << endl;
            //     }
            // } else {
            //     if(ve[i].num % 100<10)
            //     cout << "0"<< (ve[i].num % 100) << endl;
            //     else{
            //         cout <<(ve[i].num % 100) << endl;
            //     }
            // }
        }
    }
}