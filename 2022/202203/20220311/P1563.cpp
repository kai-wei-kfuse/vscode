#include<iostream>
using namespace std;
struct xx{
    bool r;
    string s;
}a[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].r>>a[i].s;
    }
    int ans=1;
    if(n==1){cout<<a[1].s;
    return 0;}
    while(m--){
        int x,y;
        cin>>x>>y;
        if(x){//x为1向右
            if(a[ans].r)//r为1朝外
            ans<=y?ans=n-(y-ans):ans-=y;
            else //r为0朝内
            ans=(ans+y==n)?n:(ans+y)%n;
        }
        else {//x为0向左
            if(a[ans].r)//朝外
            ans=(ans+y==n)?n:(ans+y)%n;
            else//朝内
            ans<=y?ans=n-(y-ans):ans-=y;
        }
        //cout<<a[ans].s;
    }
    cout<<a[ans].s;
}