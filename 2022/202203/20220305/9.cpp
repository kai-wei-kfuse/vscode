#include<iostream>
#include<algorithm>
using namespace std;
struct xx{
    string a;
    int vis[1002];
    int sum;
    double pin;
}p[101];
bool tmp(xx a,xx b){
    if(a.sum>b.sum)
    return a.sum>b.sum;
    else return a.pin<b.pin;
}
int main()
{
    int n;
    cin>>n;
    int m;
    for(int i=1;i<=n;i++){
        cin>>p[i].a>>m;
        int w=m;
       int sums=0;
        while(m--){
            int cmp;
            cin>>cmp;
            if(!p[i].vis[cmp]){
                p[i].vis[cmp]=1;
                sums++;
                p[i].sum++;
            }
            else if(p[i].vis[cmp])sums++;
        }
        p[i].pin=sums/(double)w+sums%w;
        cout<<p[i].pin;
    }
    sort(p+1,p+n+1,tmp);
    if(n>=3){
    for(int i=1;i<=2;i++){
        cout<<p[i].a<<' ';
    }
    cout<<p[3].a;
    }
    else if(n<3){
        for(int i=1;i<=n;i++){
            cout<<p[i].a<<' ';
        }
        for(int i=1;i<=3-n;i++){
            cout<<'-';
            if(i<3-n){
                cout<<' ';
            }
        }
    }
}