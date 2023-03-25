#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
ll qpow(ll x,ll n)
{
    ll base = 1;
    while(n)
    {
        if(n&1)
        {
            base = base * x;
        }
        n >>= 1;
        x = x * x;
    }
    return base;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll k, x;
        
/*         for (int x = 1; x <= 1000;x++)
        { */
                        cin >> k >> x;
        //jz
        int j =k;

        int p = j;
        int len = 0;
        auto f = [&]() {
            while(j*(p-1)<(j-1)*x)
            {
                len++;
                p = p * j;
            }
            return p/j;
        };
/*         cout <<"jz   "<< j << endl;
        cout << f() << endl; */
        int yy = f();
/*         cout << yy << endl; */
/*         cout <<j-j * (yy- 1) / (j - 1) << endl; */
        int res = x - j * (yy - 1) / (j - 1)-1;
 /*        cout << res << endl; */
        /*         cout << j * (yy - 1) / (j - 1) << endl;
                cout << res << endl; */
        vector<int> ve(len+1);
/*         cout << res << endl;
        cout << len << endl; */
        for (int i = len; i >= 0;i--)
        {
            ve[i] = res % j+10-k;
            res /= j;
        }
        for (int i = 0; i < len + 1;i++)
        {
            cout << ve[i];
        }

            cout << endl;
        /*        int xx =x- j*(f()-1)/(j-1); */
        
/*         vector<int> ve;
        while(xx)
        {
            ve.push_back(xx%j);
            xx /= j;
        }
        for (int i = ve.size() - 1; i >= 0;i--)
        {
            cout << ve[i] + k;
        }
        cout << endl; */
      

    }
}