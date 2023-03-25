#include <iostream>
using namespace std;
typedef long long ll;
int vis[20004];
int prime[20005];
ll tot = 0;
void sieve(ll n)
{
    for (ll i = 2; i <= n; i++){
        if (!vis[i])
            prime[tot++] = i;
        for (ll j = 0; prime[j] < n / i; j++){
            vis[prime[j] * i] = i;
            if (!i % prime[j])
                break;
        }
    }
    cout<<'d';
}
void solve(int i)
{
    for(int j = 1;j <= tot;j ++){
            for(int k = 1;k <= tot ;k ++){
                if(prime[j] + prime[k] == i){
                cout<<i<<'='<<prime[j]<<'+'<<prime[k]<<endl;
                return ;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    sieve(10000);
    for(int i=4;i<=n;i+=2){
        solve(i);
    }
}