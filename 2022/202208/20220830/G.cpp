#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e5 + 7;
#define int long long
using ll = long long;
ll qpow(ll x,ll m,ll n,ll flag)
{
    ll base=1;
    while(m)
    {
        if(m&1)
        {
            base = base * x;
            if(flag==0&&base>n)
            {
                return 0;
            }
        }
        m >>= 1;
        x = x * x;
    }
    return base;
}
signed main()
{
    int t;
    cin >> t;
/*     int cnt = 0; */
    int c = 0;
    while(t--)
    {
        c++;
        /*         cnt++; */
        int n,k;
        cin >> n >> k;
        if(k==1)
        {
 cout << "Case #" << c << ": " << n << endl;
            continue;
        }
        if(k>29)
        {
            cout << "Case #" << c << ": " << n << endl;
            continue;           
        }
        int ans = 0;
        for (int i = 1; i < N;i++)
        {
            if(!qpow(i, k,n,0))
            {
                break;
            }
            int l = qpow(i, k,n,0);
            int r = qpow(i + 1, k,n,1);
            if(r>n)
            {
                r = n + 1;
            }
/*             cout << l << endl; */
            int ll = l / i;
            int rr = (r  - 1) / i;
/*             cout << r << endl; */
            int cnt= rr - ll + 1;
            ans += cnt;
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
}
/* 1 8 8
8 27 8 10 12 14 16 18 20 22 24 26 28 */
/* 1 4 1 3      
4 9 2 3 
9 16 3
16 25 3 45
25 36 3
36 49 3
49 64 3
64 81 3
81 100 3
100 121 3
121 144 3
144 169 3
169 196 3
196 225 3
225 233 1  */
