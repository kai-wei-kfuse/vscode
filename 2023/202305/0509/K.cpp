#include<bits/stdc++.h>
using namespace std;

vector<int>SG(1005,-1);
int num[]={1,4,5,9};

int sg(int x){
    if(SG[x]!=-1){
        return SG[x];
    }
    set<int>se;
    for(int i=0;i<4;i++){
        if(x-num[i]>=0){
            se.insert(sg(x-num[i]));
        }
    }
    for(int i=0;;i++){
        if(!se.count(i)){
            return SG[x]=i;
        }
    }
}

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    if((sg(x) xor sg(y) xor sg(z))==0){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
    }
}