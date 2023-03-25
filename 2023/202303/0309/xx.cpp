#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,t;
    cin>>s>>t;
    int ans=0;
    for(int a=0;a<=s;a++)
    {
        for(int b=a;a+b<=s;b++)
        {
            if(a==0)
            {
                int c=s-b;
                if(b<=c)
                {
                    ans+=c-b+1;
                }
            }else
            {
                int c=t/(a*b);
                int xx=min(s-a-b,c);
                if(b<=xx)
                {
                    ans+=xx-b+1;
                }
            }
        }
    }
    cout<<ans<<endl;
}