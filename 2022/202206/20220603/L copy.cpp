#include <bits/stdc++.h>
using namespace std;
int main() {
    int s[11] = {1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1};
    int l = 0, r = 10;
    int il = l;
    int ir = l;
    while (il <= r) {
        while (s[il] == 0 && il <= r)
            il++;
        ir = il;
        while (s[ir] == 1 && ir <= r)
            ir++;
        int rr;
        if (ir==r&&s[ir] == 1) {
            rr = ir;
        } else {
            rr = ir - 1;
        }
        // cout << il << " " << rr << endl;
        cout << il << ' ' << rr << endl;
        // il - rr
        il = ir + 1;
    }
}