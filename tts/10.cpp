#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct xx {
    int x, y, z, a, b, c;
} a[100005];
bool cmp(xx a, xx b) {
    if (a.x == b.x) {
        if (a.y == b.y)
            return a.z < b.z;
        else
            return a.y < b.y;
    } else
        return a.x < b.x;
}
int main() {
    int n;
    cin >> n;
    char hh;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> hh;
        cin >> a[i].y >> hh;
        cin >> a[i].z >> hh;
        cin >> a[i].a >> hh;
        cin >> a[i].b >> hh;
        cin >> a[i].c;
    }
    sort(a + 1, a + n + 1, cmp);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << '-';
    //     cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << endl;
    // }
    a[n + 1].x = 23;
    a[n + 1].y = 59;
    a[n + 1].z = 59;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i].x != a[i - 1].a || a[i].y != a[i - 1].b ||
            a[i].z != a[i - 1].c) {
            if (a[i - 1].a < 10)
                cout << '0';
            cout << a[i - 1].a;
            cout << ':';
            if (a[i - 1].b < 10)
                cout << '0';
            cout << a[i - 1].b;
            cout << ':';
            if (a[i - 1].c < 10)
                cout << '0';
            cout << a[i - 1].c << " - ";
            if (a[i].x < 10)
                cout << '0';
            cout << a[i].x;
            cout << ':';
            if (a[i].y < 10)
                cout << '0';
            cout << a[i].y;
            cout << ':';
            if (a[i].z < 10)
                cout << '0';
            cout << a[i].z;
            if (i != n + 1)
                cout << endl;
        }
    }
    // if (a[n].a != 23 && a[n].b != 59 && a[n].c != 59) {
    //     if (a[n].a < 10)
    //         cout << '0';
    //     cout << a[n].a;
    //     cout << ':';
    //     if (a[n].b < 10)
    //         cout << '0';
    //     cout << a[n].b;
    //     cout << ':';
    //     if (a[n].c < 10)
    //         cout << '0';
    //     cout << a[n].c;
    //     cout << " - ";
    //     cout << "23:59:59";
    // }
}
/*
8
13:00:00 - 18:00:00
00:00:10 - 01:00:05
08:00:00 - 09:00:00
07:10:59 - 08:00:00
01:00:05 - 04:30:00
06:30:00 - 07:10:58
05:30:00 - 06:30:00
18:00:00 - 19:00:00

*/