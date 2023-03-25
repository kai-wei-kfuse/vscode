#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,m=1;
    cin>>n;
    for(int i;i<n;i++)
    {
        for(int j;j<n;j++)
        {
            if(m<10)cout<<"0"<<m;
            else cout<<m;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}