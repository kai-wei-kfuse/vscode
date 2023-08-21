#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int k,n;
vector<int >ve(1005);
// int chack(int x,int id){
//     int res=0;
//     int tmp=k;
//     int last=ve[id+1];
//     //cout<<last<<"|"<<endl;
//     for(int i=id;i>=1;i--){
//         if(ve[i]>last+1){
//             break;
//         }
//         if(tmp>=last+1-ve[i]){
//             tmp-=(last+1-ve[i]);
//             res=max(res,last+1);
//             last++;
//             //cout<<tmp<<"|";
//         }else{
//             break;
//         }
//     }
//     if(res>=x){
//         return 1;
//     }else{
//         if(id==1||ve[id-1]>ve[id+1]){
//             return 0;
//         }
//         last=ve[id-1]-1;
//         tmp=k;
//         for(int i=id;i>=1;i--){
//             if(ve[i]>last+1){
//                 break;
//             }
//             if(tmp>=last+1-ve[i]){
//                 tmp-=(last+1-ve[i]);
//                 res=max(res,last+1);
//                 last++;
//                 //cout<<tmp<<"|";
//             }else{
//                 break;
//             }
//         }
//         if(res>=x){
//             return 1;
//         }else{
//             return 0;
//         }
//     }
// }
int chack(int x,int id){
    int fl=0;
    int tmp=k;
    int last=x;
    for(int i=id;i<=n;i++){
        if(ve[i]>=last){
            fl=1;
            break;
        }
        if(tmp>=last-ve[i]){
            tmp-=(last-ve[i]);
            last--;
        }else{
            fl=0;
            break;
        }
    }
    if(fl){
        return 1;
    }else{
        return 0;
    }
}

signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>ve[i];
            ans=max(ans,ve[i]);
        }
        for(int i=1;i<=n;i++){
            int l=ve[i]-1,r=2e8+3000;
            while(l<r){
                int mid=(l+r+1)/2;
                if(chack(mid,i)){
                    l=mid;
                }else{
                    r=mid-1;
                }
            }
            //cout<<l<<' ';
            ans=max(ans,l);
        }
        //cout<<endl;
        cout<<ans<<'\n';
    }
}