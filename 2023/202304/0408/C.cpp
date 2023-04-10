#include <bits/stdc++.h>
using namespace std;
int main() {
    // cout.flush();
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << "? " << 1 << ' ' << 1 << endl;
        // cout.flush();
        int dis, dis1, dis2;
        cin >> dis;
        dis++;
        if (dis > x)
            cout << "? " << 1 << ' ' << dis << endl;
        else if (dis > y)
            cout << "? " << dis << ' ' << 1 << endl;
        else
            cout << "? " << 1 << ' ' << dis << endl;
        // cout.flush();
        cin >> dis1;
        dis1++;
        if (dis > x) {
            cout << "!" << dis1 << ' ' << dis << endl;
            // continue;
        } else if (dis > y) {
            cout << "! " << dis << ' ' << dis1 << endl;
            // continue;
        } else {
            if (dis1 == dis) {
                cout << "? " << dis << ' ' << 1 << endl;
                cin >> dis2;
                dis2++;
                cout << "! " << dis1 << ' ' << dis2 << endl;
            } else {
                cout << "! " << dis1 << ' ' << dis << endl;
                // continue;
            }
        }
        // cout.flush();
    }
}