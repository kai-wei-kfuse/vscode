#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll n = 2e5 + 7, mod = 1e9 + 7;
ll m, t;
ll fact[n], ifact[n], c[n];
ll fp(ll x, ll y){
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
void init(){
    c[1] = 1;fact[0] = 1;
    for (ll i = 1; i < n; i++)
        fact[i] = fact[i - 1] * i % mod;
    ifact[n - 1] = fp(fact[n - 1], mod - 2);
    for (ll i = n - 1; i > 0; i--)
        ifact[i - 1] = ifact[i] * i % mod;
    for (ll i = 2; i < n/2; i++)//可选择直接输出或者输入再输出
        c[i] = fact[2 * i - 1] * (ifact[i - 1] * ifact[i] % mod) % mod;
}
int main()
{
    cin >> t;
    init();
    while (t--){
        cin >> m;
        printf("%lld\n", c[m]);
    }
}
