#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[200005];
int main()
{
    int cmp;
    scanf("%d",&cmp);
    while(cmp--){
        int x;
        scanf("%d",&x);
        for(int i=1;i<=x;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+x+1);
        ll sum1=0,sum2=0;
        sum1+=a[1];
        for(int i=1;i<=x;i++){
            if(i+1>=x+1-i){printf("NO\n");break;}
            if(sum1+a[i+1]<sum2+a[x+1-i]){printf("YES\n");
            break;}
            sum1+=a[i+1];
            sum2+=a[x+1-i];
        }
        
    }
}