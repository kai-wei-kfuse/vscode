#include<iostream>
using namespace std;
int sum=0;
int a[100005];
int cnt=0;
int solve(int x,int y){
    //cout<<x/y<<' ';
    a[++cnt]=x/y;
    sum++;
    if(y==1)return x;
    return solve(y,x%y);
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        sum=0;
        cnt=0;
        int x,y;
        cin>>x>>y;
        solve(x,y);
        cout<<sum-1;
        for(int i=1;i<=cnt;i++){
            cout<<' '<<a[i];
        }
        cout<<endl;
    }
}