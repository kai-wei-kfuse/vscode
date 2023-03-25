#include<bits/stdc++.h>
using namespace std;
int to_in(string s)
{
    int ans=1;
    int sum=0;
/*     cout << s << endl; */
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-')
        {
            ans=-1;
        }else
        {
            sum=sum*10+(s[i]-'0');
/*             cout << "G" << endl; */
        }
        
    }
/*     cout << sum << endl; */
    return sum*ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v;
    string s;
/*     cout << to_in("-45") << endl; */
    for(int i=1;i<=m;i++)
    {
        cin>>s;
        if(s!="undo")
        {
            v.push_back(to_in(s));
        }else
        {
            string x;
            cin>>x;
            int cnt=0;
            while(v.size()&&cnt<to_in(x))
            {
                v.pop_back();
                cnt++;
            }
/*             cout << cnt << endl; */
        }
    }
    int a=0;
    for(auto it:v)
    {
/*         cout << it << " "; */
        a=((a+it)%n+n)%n;
    }
/*     cout << endl; */
    cout<<a<<endl;
}