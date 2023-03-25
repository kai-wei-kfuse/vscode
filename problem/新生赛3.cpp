#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    for(long long j=1;j<=100;j++)
    {
        if(((n-j)/100*100)+j==n)
            cout<<j<<" "<<(n-j)/100;
        }
    return 0;
}