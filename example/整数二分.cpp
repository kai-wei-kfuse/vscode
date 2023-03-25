#include<iostream>
using namespace std;
int a[1000010];
int b[1000010];
int main()
{
    freopen("A.in","r", stdin); 
    freopen ("A.out","w", stdout); 
    int len=0,t=0;
    int n=0,j=0;
    int cnt=0;
    scanf("%d %d",&len,&t);
    for(int i=1;i<=len;i++){
        scanf("%d",&a[i]);
    }
    if(a[1]>a[2])j=1;
    for(int i=1;i<=len;i++){
        cnt=0;
        int r=len,l=1,mid;
        while(r>=l)
        {
            cnt++;
            mid=(l+r) >> 1;
            if(j==1)
            {
                if(a[mid]==a[i])break;
                if(a[i]>=a[mid])r=mid-1;
                else l=mid+1;
            }
            else
            {
                if(a[mid]==a[i])break;
                if(a[i]<=a[mid])r=mid-1;
                else l=mid+1;
            }
        }
        //cout<<cnt<<endl;
        if(a[mid]==a[i])
        b[a[mid]]=cnt;
    }
    while(t--){
        scanf("%d",&n);
        if(b[n])
            printf("%d\n",b[n]);
        else
            printf("NONE\n");
    }
}