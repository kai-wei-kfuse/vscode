#include<iostream>
using namespace std;
int n,m,k;
int main()
{
    cin>>n;
    while(n--){
        scanf("%d %d",&m,&k);
        if(m<=k)printf("1\n");
        if(k==1 && m>k)printf("-1\n");
        if(m%(k-1)==0)printf("%d\n",(m/k-1)*2+1);
        if(m%(k-1)!=0)printf("%d\n",(m/k)*2+1);
    }
}