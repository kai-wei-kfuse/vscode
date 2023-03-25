#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
char a;
double len,x,y;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        len=0,x=0,y=0;
        for(int j=1;j<=n;j++){
            cin>>a;
            if(a=='R')x++;
            if(a=='L')x--;
            if(a=='U')y++;
            if(a=='D')y--;
            //cout<<x<<' '<<y;
            len=max(len,sqrt(x*x+y*y));
        }
        printf("%lf\n",len);
    }
}