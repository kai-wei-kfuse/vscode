#include<iostream>
const double pi=3.141592;
using namespace std;
double read(){
    double x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main()
{
    int n;
    n=read();
    int a,b;
    double d;
    while(n--){
        a=read();
        b=read();
        d=read();
        printf("%.6f\n",d*d/2);
    }
}