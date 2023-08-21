#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num=(n-1)*n/2;
        map<int,int >mp;
        for(int i=1;i<=num;i++){
            int tmp;
            cin>>tmp;
            mp[tmp]++;
        }
        vector<int >ans;
        int cnt=n-1;
        for(auto &it:mp){
            int tmp=it.second;
            while(tmp-cnt>=0&&cnt>0){
                tmp-=cnt;
                ans.push_back(it.first);
                cnt--;
            }
        }
        ans.push_back(1e9);
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }

}