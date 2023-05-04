#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        s=" "+s;
        vector<pair<int ,int> >same,notsame;
        map<int ,int >mp;
        if(n&1){
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=1;i*2<=n;i++){
            if(s[i]==s[n-i+1]){
                same.push_back({s[i],s[n-i+1]});
                mp[s[i]]++;
            }
            else{
                notsame.push_back({s[i],s[n-i+1]});
            }
        }
        int num=same.size();
        int maxn=0,x;
        for(auto i:mp){
            if(i.second>maxn){
                maxn=i.second;
                x=i.first;
            }
        }
        if(maxn<=num/2){
            if(num&1)
                cout<<num/2+1<<endl;
            else
                cout<<num/2<<endl;
        }else{
            int last=maxn-(num-maxn);
            for(auto i:notsame){
                if(i.first!=x&&i.second!=x){
                    last--;
                }
            }
            if(last>0){
                cout<<"-1"<<endl;
            }else{
                cout<<maxn<<endl;
            }
        }
    }
}