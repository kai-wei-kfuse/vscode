#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define eps 1e-8
double a[10001][3];
int n,m;
double f(double x)
{
    double y=a[1][0]*x*x+a[1][1]*x+a[1][2];
    //cout<<y<<' ';
    for(int i=2;i<=m;i++){
        y=max(y,a[i][0]*x*x+a[i][1]*x+a[i][2]);
        //cout<<y_<<'|';
    }
    return y;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        //memset(a,0,sizeof(a));
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%lf %lf %lf",&a[i][0],&a[i][1],&a[i][2]);
        }
    double l=0,r=1000;
    double midl,midr;
    while(r-l>eps){
        midl=l+(r-l)/3;
        midr=r-(r-l)/3;
        //cout<<midl<<' '<<midr;
        if(f(midl)>f(midr))l=midl;
        else r=midr;
    }
    printf("%.4lf\n",f(l));
    }
}