#include<iostream>
#include<algorithm>
using namespace std;
struct xx{
    string a;
    int num;
}st[10005];
bool cmp(xx a, xx b){
    if(a.num!=b.num){
        return a.num>b.num;
    }
    else return a.a<b.a;
}
int main()
{
    int n,c,m;
    cin>>n>>c>>m;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>st[i].a>>st[i].num;
        if(st[i].num>=60){
            if(st[i].num>=c)
            sum+=50;
            else sum+=20;
        }
    }
    sort(st+1,st+n+1,cmp);
    cout<<sum<<endl;
    int j=1,k=1;
    for(int i=1;j<=m;i++){
        cout<<j<<' ';
        if(st[j+1].num!=st[j].num){j+=k;k=0;}
        else k++;
        cout<<st[i].a<<' '<<st[i].num<<endl;
    }
}