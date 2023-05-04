#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        n-=4;
        cout<<(11+(n-1))*n+26<<endl;
    }
}