#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int even=0,odd=0;
        for(int i=1;i<=n;i++){
            int tmp;
            cin>>tmp;
            if(tmp&1){
                odd++;
            }else{
                even++;
            }
        }
        if(odd&1){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
}