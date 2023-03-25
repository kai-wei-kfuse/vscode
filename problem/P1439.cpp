#include<iostream>
using namespace std;
int a[100002];
int b[100002];
int map[100002];
int t[100002];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        map[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    t[i]=map[b[i]];
    //cout<<map[i]<<'|';
    //cout<<t[i]<<' ';
    }
    int len=0;
    map[++len]=t[1];
    for(int i=1;i<=n;i++){
        if(map[len]<t[i])map[++len]=t[i];
        else{
            int l=0,r=len+1,mid;
            while(l+1!=r){
                mid=l+(r-l)/2;
                if(t[i]>map[mid])l=mid;
                else r=mid;
            }
            map[r]=t[i];
        }
    }
    cout<<len;
}