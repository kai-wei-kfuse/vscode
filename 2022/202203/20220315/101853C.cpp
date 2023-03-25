#include<iostream>
using namespace std;
int a[100005],b[100005];
int t[100005];
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
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    /*for(int i=1;i<=n;i++){
        cin>>a[i];
    }*/
    //msort(1,n);
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    //cout<<endl;
    //cout<<ans;
    while(n--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            cin>>tmp;
            b[tmp]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int tmp;
            cin>>tmp;
            a[i]=b[tmp];

        }
        ans=0;
        msort(1,n);
        cout<<ans<<endl;
    }
}