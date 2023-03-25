#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
struct xx{
long long x,y;
}a[1005];
long long sum;
int main()
{
    
    int n;  
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        long long sum=0;
        for(int i=1;i<=n;i++){
            scanf("%ld%ld",&a[i].x,&a[i].y);
        }
        for(int i=1;i<n;i++){
            sum+=(a[i].x*a[i+1].y-a[i+1].x*a[i].y);
            //cout<<sum<<' ';
        }
        sum+=(a[n].x*a[1].y-a[1].x*a[n].y);
        //cout<<sum<<endl;
        sum=abs(sum);
        if(sum%2==1){
        long long ans=sum/2;
        printf("%ld.50\n",ans);
        }
        else {
            long long ans=sum/2;
        printf("%ld.00\n",ans);
        }
    }
}