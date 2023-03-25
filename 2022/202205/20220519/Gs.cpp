#include <iostream>
using namespace std;
int prime[100005], these[100005];
using ll = long long;
const int N = 1e5 + 5;
int indexs;
bool is_prime[N];
int shai() {
    int p = 0;
    //初始化，先让所有的数都为素数
    for (int i = 0; i <= N; i++) {
        is_prime[i] = true;
    }
    //记录1和0的特殊情况
    is_prime[1] = is_prime[0] = 0;
    for (int i = 2; i <= N; i++)  //仅筛到 根号
    {
        if (is_prime[i]) {
            prime[indexs++] = i;
            // cout << i << ' ';
            //这里直接从i * i开始 ，因为 i*（1....i-1）一定被记录过
            if (1ll * i * i <= N) {
                //否定素数的倍数是素数
                for (int j = i * i; j <= N; j += i)
                    is_prime[j] = 0;
            }
        }
    }
    return indexs;
}
int main() {
    shai();
    int n;
    cin >> n;
    int tmp;
    while (n--) {
        int num = 0, cnt = 0;
        cin >> tmp;
        int tmpp = tmp;
        int flag = 0;
        if (is_prime[tmp]) {
            cout << "0" << '\n';
        } else {
            for (int i = 0; prime[i] <= tmp / prime[i]; i++) {
                // cout << prime[i] << ' ' << tmp << endl;
                if (tmp % prime[i] == 0) {
                    these[++cnt] = prime[i];
                }
                while (tmp % prime[i] == 0) {
                    tmp /= prime[i];
                }
            }
            if (is_prime[tmp] == 1) {
                these[++cnt] = tmp;
            }
            for (int i = 1; i <= cnt; i++) {
                cout << these[i] << ' ';
            }
            if (cnt == 1) {
                cout << "-1" << '\n';
            } else {
                cout << these[cnt] * these[cnt - 1] << '\n';
            }
        }
    }
}