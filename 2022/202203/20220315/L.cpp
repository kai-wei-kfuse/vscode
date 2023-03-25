#include<iostream>
using namespace std;
int a1,b1,a2,b2;
int p[100005];
int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>a1>>b1>>a2>>b2;
        p[a1]+=1;
        p[a2]-=1;
    }
    //for(int i=1;i<=10;i++)cout<<p[i]<<' ';
    //cout<<endl;
    int sum=0;
    for(int i=1;i<=100000;i++){
        p[i]=p[i]+p[i-1];
        //if(i<11)
        //cout<<p[i]<<' ';
        if(p[i])sum++;
    }
    cout<<sum;
}