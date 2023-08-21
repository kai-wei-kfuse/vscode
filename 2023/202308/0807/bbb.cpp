#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int x=-1;
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            if(s[i]>='5')
            {
                x=i;
                break;
            }
        }
        if(x==-1)
        {
            cout<<s<<endl;
        }else
        {
            if(x==0)
            {
                string s1="1";
                for(int i=0;i<len;i++)
                {
                    s1+='0';
                }
                cout<<s1<<endl;
                //cout<<1<<string(s.size(),'0')<<endl;
            }else
            {
                while(x-1>=0)
                {
                    s[x-1]++;
                    if(s[x-1]<'5')
                    {
                        break;
                    }
                    x--;
                }
                if(x==0)
                {
                    string s1="1";
                    for(int i=0;i<len;i++)
                    {
                        s1+='0';
                    }
                    cout<<s1<<endl;
                    //cout<<1<<string(s.size(),'0')<<endl;
                }else
                {
                    string s1=s.substr(0,x);
                    for(int i=0;i<len-x;i++)
                    {
                        s1+='0';
                    }
                    cout<<s1<<endl;
                    //cout<<s.substr(0,x)+string(s.size()-x,'0')<<endl;
                }
                
            }
        }
    }
}
