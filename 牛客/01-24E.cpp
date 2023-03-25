#include<iostream>
using namespace std;
int n,m,k;
int t;
int main()
{
    cin>>n;
    while(n--){
        scanf("%d %d",&m,&k);  
        t=0;  
        if(m<=k){printf("1\n");continue;}
        if(k==1 && m>k){printf("-1\n");continue;}
        t=(m/k)*2;
        if(m-(k-1)*t<=k)t++;
        else t+=3;
        printf("%d\n",t);
    }
}