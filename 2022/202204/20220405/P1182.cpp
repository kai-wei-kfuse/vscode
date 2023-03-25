#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
ll a[100005];
int n, m;
ll maxn, minn;
ll chack(ll mins) {
    ll sum = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (tmp + a[i] > mins) {
            sum++;
            tmp = 0;
        }
        tmp += a[i];
    }
    return sum >= m;
}
int main() {
    // freopen("in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    // freopen("out.txt", "w", stdout);
    // //输出重定向，输出数据将保存out.txt文件中
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn += a[i];
        minn = max(a[i], minn);
    }
    ll l = minn - 1, r = maxn + 1, mid;
    while (l + 1 != r) {
        mid = l + ((r - l) >> 1);
        cout << mid << endl;
        if (chack(mid))
            l = mid;
        else
            r = mid;
    }
    cout << r;
}