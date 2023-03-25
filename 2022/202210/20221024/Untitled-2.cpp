#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    s=' '+s;
    int ans1=0,ans2=0;
    for(int i=1;i<=n/2;i++)
    {
        ans1+=s[i]-'A';
    }
    for(int i=n/2+1;i<=n;i++)
    {
        ans2+=s[i]-'A';
    }  
    for(int i=1;i<=n/2;i++)
    {
        s[i]=(s[i]-'A'+ans1)%26+'A';
    }  
    for(int i=n/2+1;i<=n;i++)
    {
        s[i]=(s[i]-'A'+ans2)%26+'A';
    }     

    for(int i=1;i<=n/2;i++)
    {
        s[i]=(s[i]-'A'+s[i+n/2]-'A')%26+'A';
        cout<<s[i];
    }
/* 
    cout<<s<<endl; */
}