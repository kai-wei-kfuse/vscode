#include<iostream>
#include<algorithm>
using namespace std;
int a[12];
 int cnt=1;
int x1,x2,x3,x4,x5;
int main()
{
    int n;
    cin>>n;
    
    while(n--){
        int sum=0;
        for(int i=1;i<=10;i++){
            cin>>a[i];
            sum+=a[i];
        }  
        sort(a+1,a+11);//x1+x2=a[1],x4+x5=a[10]
        sum/=4;
        x3=sum-a[1]-a[10];
        x1=a[2]-x3;
        x2=a[1]-x1;//a[9]=x5+x3
        x5=a[9]-x3;
        x4=a[10]-x5;
       
        printf("Case %d: %d %d %d %d %d\n",cnt++,x1,x2,x3,x4,x5);
    }
}