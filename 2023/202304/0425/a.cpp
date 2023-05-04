#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>ve(n+1);
        for(int i=1;i<=n;i++){
            cin>>ve[i];
        }
        vector<int >ve2(n+1);
        for(int i=1;i<=n;i++){
            cin>>ve2[i];
        }
        int ans=0,ansid=-1;
        for(int i=1;i<=n;i++){
            if(m>=ve[i]){
                if(ans<ve2[i]){
                    ans=ve2[i];
                    ansid=i;
                }
            }
            m--;
        }
        cout<<ansid<<endl;
    }
    return 0;
}