#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
int get1(int n)
{
    int x = n / 3;
    int res = 1e15;
    if(__gcd(x-1,x+2)==1&&__gcd(x-1,x)==1&&__gcd(x,x+2)==1)
    {
        res = min(res, 3ll);
    }
    x++;
    if(__gcd(x-3,x+1)==1&&__gcd(x-3,x)==1&&__gcd(x,x+1)==1)
    {
        res = min(res, 4ll);
    }
    return res;
}
int get2(int n)
{
    int x = n / 3;
    int res = 1e15;
    if(__gcd(x-1,x+3)==1&&__gcd(x-1,x)==1&&__gcd(x,x+3)==1)
    {
        res = min(res, 4ll);
    }
    x++;
/*     cout << res << endl; */
/*     cout << x << endl;
    cout << x - 2 << " " << x + 1 << endl;
    cout << __gcd(x - 2, x + 1) << " " << __gcd(x - 2, x) << " "
         << __gcd(x, x + 1) << endl; */
    if(__gcd(x-2,x+1)==1&&__gcd(x-2,x)==1&&__gcd(x,x+1)==1)
    {
        res = min(res, 3ll);
    }
    return res;    
}
signed main() {
    int t;
    cin >> t;
    int cnt = 0;
    while (t--) {
        cnt++;
        int n;
        cin >> n;
        /*         cin >> n; */
        cout << "Case #" << cnt << ": ";
        if (n % 2 != 0) //1
        {
            cout << '1' << '\n';
        } else //2
        {
            if (n == 6)
                cout << "-1" << '\n';
            else 
            {
                if ((n / 2) % 2!=0) 
                {
                    if (n % 3 == 0) 
                    {
                        cout << 2 << endl;
                    } 
                    else 
                    {
                        if(n%3==1)
                        {
                            cout<<get1(n)<<'\n';
                        }else
                        {
                            cout<<get2(n)<<'\n';
                        }
                    }
                } else 
                {
                    cout << '2' << '\n';
                }
            }
        }
    }
}