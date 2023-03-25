#include<iostream>//二分
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c,d;
#define eps 1e-4//精确度10的-4次方
double fx(double x)//（用函数比较好），求函数值
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    cin>>a>>b>>c>>d;
    //scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(int i=-100;i<=100;i++)
    {
        double r=i+1,l=i,mid;
        if(fabs(fx(l))==0)
        printf("%.2f ",l);
        //else if(fabs(fx(r))<eps)
            //continue;
        if(fx(l)*fx(r)<0)//有根（且区间内只有一个）
        {
            while(r-l>eps)//在精确值未到之前继续分
            {
                mid=(r+l)/2;
                if(fx(l)*fx(mid)>0)l=mid;//去中点之后得到三个点，如果左边两个同号说明根在右边区间，
                //因此左端点移到中点
                else if(fx(mid)*fx(r)>0)r=mid;//同理右端点移到中点
            }
        printf("%.2f ",l);
        }
    }
}
