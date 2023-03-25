#include<iostream>//外星密码
#include<string>
using namespace std;
/*
int main()
{
    string in,ans;
    int s,end;
    cin>>in;
    int len=in.length();
    for(int i=0;i<len;i++)
    {
        if(in[i]=='[')
        {
            int r=i,l=i;
            while((in[r]!=']'))r++;
            for(int k=1;k<=in[l+1]-'0';k++)
                {
                    ans+=in.substr(l+2,r-l-2);
                }
            i=r+1;
        }
        else
        ans+=in[i];
    }
    cout<<ans;
}
*/
/*
int i=0;
string m(string n)
{
    string tmp="",cmp;
    while(n[i++]!='\0')
    {
        if(n[i-1]=='[')
        {
            int x;
            if(n[i+1]-'0'>=0&&n[i+1]-'0'<=9)x=(n[i++]-'0')*10+n[i++];
            else x=n[i++]-'0';
            cmp=m(n);
            while(x--)tmp+=cmp;
        }
        else if(n[i-1]==']')
            return tmp;
        else tmp+=n[i-1];
    }
    return tmp;
}
int main()
{
    string n;
    cin>>n;
    cout<<m(n);
}
*/
string m()
{
    string tmp="",cmp="";
    char c;
    int x;
    while(cin>>c)
    {
        if(c=='[')
        {
            cin>>x;
            cmp=m();
            while(x--)tmp+=cmp;
        }
        else if(c==']')return tmp;
        else tmp+=c;
    }
    return tmp;
}
int main()
{
    cout<<m();
    return 0;
}