#include <iostream>
using namespace std;
int r[105], w[105], maxr, maxw;
int main() {
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        maxr = 0, maxw = 0;
        for (int i = 1; i <= y; i++) {
            cin >> r[i] >> w[i];
            maxr = max(maxr, r[i]);
            maxw = max(maxw, w[i]);
        }
        if (x < maxr + maxw) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            for (int i = 1; i <= maxr; i++) {
                cout << "R";
            }
            for (int i = 1; i <= maxw; i++) {
                cout << "W";
            }
            if (x > maxr + maxw)
                for (int i = 1; i <= x - (maxr + maxw); i++)
                    cout << "W";
            cout << '\n';
        }
    }
}