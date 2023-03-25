#include <iostream>
using namespace std;
typedef unsigned long long ull;  // 通过ull自然溢出来实现%2^64

// P = 131 或  13331 Q=2^64，在99%的情况下不会出现冲突
const int P = 131;
// char a[100005];
ull h[100005], p[100005];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, m;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        a = "?" + a;
        p[0] = 1;
        int len = a.size() - 1;
        for (int i = 1; i <= len; i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + a[i];
        }
        int flag = 0;
        for (int i = 1; i < len - 1; i++) {
            for (int j = 1; i + j < len; j++) {
                if ((get(1, i) <= get(i + 1, i + j) &&
                     get(i + 1, i + j) >= get(j + i + 1, len)) ||
                    (get(1, i) >= get(i + 1, j + i) &&
                     get(i + 1, j + i) <= get(j + i + 1, len))) {
                    cout << i << ' ' << i + j << endl;
                    cout << a.substr(1, i) << ' ' << a.substr(i + 1, i + j)
                         << ' ' << a.substr(j + i + 1) << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
    }
}