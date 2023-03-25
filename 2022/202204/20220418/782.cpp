#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string a = "";
        int x, r, b;
        cin >> x >> r >> b;
        int t = r / (b + 1);
        int tx = r / t;
        int last = r % (b + 1);
        // cout << last << endl;
        while (x > 0) {
            int tmp = t;
            while (tmp-- && x > 0) {
                a += 'R';
                x--;
            }
            if (last) {
                a += 'R';
                x--;
                last--;
            }
            if (b > 0) {
                a += 'B';
                x--;
            }
            b--;
        }
        cout << a << endl;
    }
}