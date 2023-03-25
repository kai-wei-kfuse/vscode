#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int cnt = 0,tmp;
        for (int i = 1; i <= 4;i++){
            cin >> tmp;
            if(tmp>0)
                cnt++;
        }
        if(cnt==0){
            cout << "Typically Otaku" << endl;
        }else if(cnt==1){
            cout << "Eye-opener" << endl;
        }else if(cnt==2){
            cout << "Young Traveller" << endl;
        }else if(cnt==3){
            cout << "Excellent Traveller" << endl;
        }else if(cnt==4){
            cout << "Contemporary Xu Xiake" << endl;
        }
    }
}