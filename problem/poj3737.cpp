#include<iostream>//小数三分
#include<math.h>
using namespace std;
#define eps 1e-8
#define Pi 3.1415926
double s;
double v(double r)
{
    double l=s/r/Pi-r;
    double h=sqrt(l*l-r*r);
    return Pi*r*r*h/3;
}
int main()
{
    while(scanf("%lf",&s)!=EOF)
    //while(~scanf("%lf", &s))
    {
    double l=0,r=s/Pi,midl,midr;
    while(r-l>eps){
        midl=l+(r-l)/3;
        midr=r-(r-l)/3;
        if(v(midl)<v(midr))l=midl;
        else r=midr;
    }
    double L=s/r/Pi-l;
    double h=sqrt(L*L-l*l);
    double V=Pi*l*l*h/3;
    printf("%.2lf\n%.2lf\n%.2lf\n",V,h,l);
    }
}