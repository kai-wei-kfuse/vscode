#include<iostream>
using namespace std;
double m[]={12.01,1.008,16.00,14.01};
int main()
{
    int n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        int len=a.length();
        double x=0;
        double sum=0;
        int tmp=1;
        for(int i=len-1;i>=0;i--){
            if(a[i]>='0'&&a[i]<='9'){
                x=x+(int)(a[i]-'0')*tmp;
                tmp*=10;
            }
            else{
                //cout<<x<<endl;
                if(!x)x=1;
                if(a[i]=='C')sum+=m[0]*x;
                if(a[i]=='H')sum+=m[1]*x;
                if(a[i]=='O')sum+=m[2]*x;
                if(a[i]=='N')sum+=m[3]*x;
                tmp=1;
                x=0;
            }
        }
        printf("%.3f\n",sum);
    }
}