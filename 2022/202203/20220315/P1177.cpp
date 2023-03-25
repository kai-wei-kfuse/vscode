#include<iostream>
using namespace std;
int a[500005];
int t[500005];
long long ans=0;
void msort(int l,int r){
    if(l==r)return;
    int mid=l+((r-l)>>1);
    //int mid=(r+l)>>1;
    msort(l,mid);msort(mid+1,r);
    for(int i=l,j=mid+1,k=l;k<=r;k++){
        if(i==mid+1)
            t[k]=a[j++];
        else if(j==r+1){
            t[k]=a[i++];
        }
        else if(a[i]<=a[j]){
            t[k]=a[i++];
            
        }
        else{
            t[k]=a[j++];
            ans+=(mid-i+1);
        }
    }
    for(int i=l;i<=r;i++)a[i]=t[i];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    msort(1,n);
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    //cout<<endl;
    cout<<ans;
}