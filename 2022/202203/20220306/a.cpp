#include<iostream>
using namespace std;
int hturn(int x){
    return x*60*60;
}
int mturn(int x){
    return x*60;
}
int main()
{
    int n;
    cin>>n;
    int h1,t1,s1,h2,t2,s2;
    for(int i=1;i<=n;i++){
        cin>>h1>>t1>>s1>>h2>>t2>>s2;
    if(hturn(h1)+mturn(t1)+s1==hturn(h2)+mturn(t2)+s2){
        printf("Case %d: Yes\n",i);
    }
    else{printf("Case %d: No\n",i);}
    }
}