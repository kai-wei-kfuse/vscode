#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len=s.size();
        queue<pair<int,int> >q;
        for(int i=0;i<len;i++){
            while(!q.empty()&&q.front().first>s[i]){
                q.pop();
            }
            if(q.empty()||q.front().first<=s[i])
                q.push({s[i],i});
        }
        vector<int>vis(len,0);
        string ans="";
        while(!q.empty()){
            ans+=q.front().first;
            vis[q.front().second]=1;
            cout<<(char)q.front().first;
            q.pop();
        }
        for(int i=0;i<len;i++){
            if(!vis[i])
                ans+=s[i];
        }
        cout<<endl;
        //cout<<ans<<endl;
    }
}