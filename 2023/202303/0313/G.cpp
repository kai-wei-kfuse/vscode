#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int qpow(int x,int n)
{
    int base = 1;
    while(n)
    {
        if(n&1)
        {
            base = base * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return base;
}
int res;
int c(int n)
{
    int base = 1;
    for (int i = 1; i <= 4;i++)
    {
        base = base * n%mod;
        n--;
    }
    return base = base * res % mod;
}
signed main(){
    res = qpow(4 * 3 * 2, mod - 2);
    int t;
    cin >> t;
    int cnt = 0;
    while(t--){
        cnt++;
        int n, m;
        cin >> n >> m;
        cout << "Case " << cnt << ": ";
        if(n-2<=0||m-2<=0)
        {
            cout << 0 << endl;
            continue;
        }else
        {
            cout << c(n + 1) * c(m + 1) % mod<<endl;
            continue;
        }
        
    }
}