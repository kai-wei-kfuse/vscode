#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2010, mod = 1e9 + 7;


int c[N][N];


void init()
{
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main() {
    int n, h, num;
    cin >> n >> num >> h;
    int n_ = n - 1;
    int all = 0;
    vector<int> ve(num + 1);
    for (int i = 1; i <= num; i++) {
        cin >> ve[i];
        all += ve[i];
    }
    int me = ve[h] - 1;
    if (all < n) {
        cout << "-1";
    } else if (all - ve[h] < n_) {
        cout << "1";
    } else {
        init();
        cout << (double)ve[h] / (double)c[all-1][n_];
    }
}