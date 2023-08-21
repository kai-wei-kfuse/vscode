#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct xx{
    int x,y,id;
};

bool cmp(xx a,xx b){
    return a.x+b.y>b.x+a.y;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<xx >ve(n+1);
        for(int i=1;i<=n;i++){
            cin>>ve[i].x;
            ve[i].id=i;
        }
        for(int i=1;i<=n;i++){
            cin>>ve[i].y;
        }
        sort(ve.begin()+1,ve.end(),cmp);
        vector<int >ans;
        //ans.push_back(ve[1].id);
        int x=upper_bound(ve.begin()+2,ve.end(),ve[1],cmp)-ve.begin();
        x--;
        for(int i=1;i<=x;i++){
            ans.push_back(ve[i].id);
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}