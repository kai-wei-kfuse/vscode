#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,r,m,x,i,mid,j=1;
int l , cnt = 0;
int b[1000010],a[1000010];
int main(){
 freopen("A.in","r", stdin); 
    freopen ("A.out","w", stdout); 
 scanf("%d %d",&n,&m);
for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
if(a[1]>a[n])
{
 for(i=1;i<=n;i++){
  r=n+1;
  l=0;
  cnt=0;
 while (l+1!=r) {
     mid = (l + r) / 2;
      cnt++;
    if (a[mid] == a[i]) break;
    if (a[mid] > a[i]) l = mid;
    else r = mid;
}
 if (a[mid] == a[i])
  b[a[i]]=cnt;
}
 for(i=0;i<m;i++){
  scanf("%d",&x);
 if(b[x]!=0)
  printf("%d",b[x]);
 else printf("NONE");
 if(i!=m-1) printf("\n");
 }
}
 //jian();
else
{
 for(i=0;i<m;i++){
  r=n+1;
  l=0;
  cnt=0;
 while (l+1!=r) {
     mid = (l + r) / 2;
     cnt++;
    if (a[mid] == x) break;
    if (a[mid] > x) r = mid;
    else l = mid;
}
 if (a[mid] == a[i])
 b[a[i]]=cnt;}
 for(i=0;i<m;i++){
  scanf("%d",&x);
 if(b[x]!=0)
  printf("%d",b[x]);
 else printf("NONE");
 if(i!=m-1)printf("\n");
 }
}
// zeng();
}