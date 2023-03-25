#include<iostream>
#include<algorithm>
using namespace std;
int a[1010][1010],f[1010][1010];
int main()
{
    int r;
    cin>>r;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=i;j++)
        cin>>a[i][j];
    for(int i=r;i>=1;i--)
        for(int j=1;j<=i;j++)
        {
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
        }
        cout<<f[1][1];
        return 0;
}