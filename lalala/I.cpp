#include <iostream>
typedef long long ll;
using namespace std;
#define mod 1000000007
int n, m;  // n:店，m：花
ll sum = 0;
void dfs(int tmpn, int tmpm, int f) {
    if (tmpn == 0 && tmpm == 0) {
        if (f != 1)
            return;
        else {
            sum++;
            sum %= mod;
        }
    }
    if (f == 0)
        return;
    if (tmpm > 0)
        dfs(tmpn, tmpm - 1, f - 1);
    if (tmpn > 0)
        dfs(tmpn - 1, tmpm, f * 2);
}
int main() {
    cin >> n >> m;
    if (n > m) {
        cout << 0;
        return 0;
    }
    // 01
    m -= 1;
    int f = 2;
    dfs(n, m, f);
    cout << sum;
    return 0;
}