#include<iostream>
using namespace std;
int n;
long long a,b[1000000];
int main()
{
    cin>>n;
    b[4]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(b[a]!=0)cout<<b[a]%1000000007<<endl;
        else
        {int j;
        for(j=4;j<=a;j++)
        {
        if(b[j]!=0)continue;
        else
            {   
                b[j]=b[j-1]+j-3;
            }
        }
        cout<<b[a]%1000000007<<endl;
        }
    }
    return 0;
}