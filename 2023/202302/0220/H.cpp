#include<bits/stdc++.h>
using namespace std;
map<string,string>cz(string s)
{
    map<string,string>mp;
    string ss;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='\"')
        {
            int j=i+1;
            ss="\"";
            while(s[j]!='\"')
            {
                ss+=s[j];
                j++;
            }
            ss+="\"";
            i=j+1;
        }
        if(s[i]==':')
        {
            int j=i+1;
            if(s[j]=='\"')
            {
                j++;
                string x;
                x="\"";
                while(s[j]!='\"')
                {
                    x+=s[j];
                    j++;
                }
                x+="\"";                    
                mp[ss]=x;
            }else if(s[j]=='{')
            {
                j++;
                string tmp;
                while(s[j]!='}')
                {
                    tmp+=s[j];
                    j++;
                }
                map<string,string>tp=cz(tmp);
                for(auto [u,v]:tp)
                {
                    mp[ss+"."+u]=v;
                }
                mp[ss]="{"+tmp+"}";
            }   
            i=j;
        }
        ss="";
    }  
    return mp;  
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<string,string>mp;
        string s;
        cin>>s;
        s.pop_back();
        s+=',';
        string ss;
        for(int i=1;i<s.size()-1;i++)
        {
            if(s[i]=='\"')
            {
                int j=i+1;
                ss="\"";
                while(s[j]!='\"')
                {
                    ss+=s[j];
                    j++;
                }
                ss+="\"";
                i=j+1;
            }
            if(s[i]==':')
            {
                int j=i+1;
                if(s[j]=='\"')
                {
                    j++;
                    string x;
                    x="\"";
                    while(s[j]!='\"')
                    {
                        x+=s[j];
                        j++;
                    }
                    x+="\"";                    
                    mp[ss]=x;
                }else if(s[j]=='{')
                {
                    j++;
                    string tmp;
                    while(s[j]!='}')
                    {
                        tmp+=s[j];
                        j++;
                    }

                    map<string,string>tp=cz(tmp);
                    for(auto [u,v]:tp)
                    {
                        mp[ss+"."+u]=v;
                    }
                    mp[ss]="{"+tmp+"}";
                }   
                i=j;
            }
            ss="";
        }
        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            string x;
            cin>>x;
            if(mp.find(x)==mp.end())
            {
                cout<<"Error!"<<endl;
            }else
            {
                cout<<mp[x]<<endl;
            }
        }
    }
}