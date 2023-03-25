#include<iostream>//二分
using namespace std;
int a[1000010];
int x;
int n,m;
int find(int l,int r)
{
    /*while(l<r)
     {
         int mid=l+(r-l)/2;
         if(x>=a[mid])l=mid;
         else r=mid-1;
     }
     if(x==a[l])return l;
     else return -1;*/
     while(l<r)
     {
         int mid=l+(r-l)/2;
         if(x<=a[mid])r=mid;
         else l=mid+1;
     }
     if(x==a[l])return l;
     else return -1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        cout<<find(1,n)<<' ';
    }
}