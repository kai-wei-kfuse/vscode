#include<iostream>
using namespace std;
int a[100010];
int p[100010];
int b[100010];
int main()
{
    int i=0,len1=0,ans;
    while(~scanf("%d",&a[++i]));//循环输入
    int n=i-1;//最后一次没有输入因此跳出循环，n=i-1
    b[0] = 100000 ;
    b[++len1]=a[1];
    for(i=2;i<=n;i++){
        if(a[i]<=b[len1]){
            b[++len1]=a[i];
        }
        else 
        {
            int l=0,r=len1,mid;
            while(l<=r){
                mid=l+(r-l)/2;
                if(a[i]<=b[mid]){
                    ans=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            b[ans+1]=a[i];
        }
        /*for(int j=1;j<=len1;j++){
                cout<<b[j]<<' ';
            }
            cout<<endl;*/
    }
    cout<<len1<<endl;
    int sum=0;
    int m=0;
    while(m<n){
        int last=10000000;
        for(int j=1;j<=n;j++){
            if(a[j]>0 && a[j]<=last){
                m++;
                last=a[j];
                a[j]=-1;
            }
        }
        sum++;
    }
    cout<<sum;
}