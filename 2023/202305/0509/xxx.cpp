#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 9;

int a[N], l, r;


int sg(int x)
{
    return (x % (l + r)) / l;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;cin >> n >> l >> r;
    //for(int i = 1;i <= n; ++ i)cin >> a[i];
    // for(int i = 0;i <= 20; ++ i)
        // cout << "sg(" << i << ") = " << sgk(i) << " = " << sg(i) << '\n';
    int ans = 0;
    //for(int i = 1;i <= n; ++ i)ans ^= sg(a[i]);
    cout<<sg(n)<<endl;
    // if(ans)cout << "First" << '\n';
    // else cout << "Second" << '\n';

    return 0;
}