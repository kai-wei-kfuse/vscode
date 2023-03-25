#include<iostream>
#include<algorithm>
using namespace std;
int W,L,sum;
int b[100005];
int cnt;
int main()
{
    //freopen("A.in","r", stdin); 
    //freopen ("A.out","w", stdout); 
    char a;
    //if(a=='W')b[cnt++]=1;
    //else b[cnt++]=-1;
    while(a!='E'){
        cin>>a;
        //if(a!='W'&&a!='L')a=getchar();
        if((L>=11||W>=11)&&abs(L-W)>=2){
            cout<<W<<':'<<L<<endl;
            W=0;L=0;
        }
            if(a=='W'){
                W++;
                sum++;
                b[++cnt]=1;
            }
            if(a=='L'){
                L++;
                sum++;
                b[++cnt]=-1;
            }
            if(a=='E')break;
        //a=getchar();
    }
    //cout<<cnt<<'|'<<sum<<endl;
    b[++cnt]=2;
    cout<<W<<':'<<L<<endl<<endl;
    int i=0; W=0,L=0,sum=0;
    while(b[++i]!=2){
        //if(b[i]!='W'&&b[i]!='L')i++;
        if((L>=21||W>=21)&&abs(L-W)>=2){
            cout<<W<<':'<<L<<endl;
            W=0;L=0;sum=0;
        }
            if(b[i]==1){
                //cout<<W<<':'<<L<<endl;
                W++;
            }
            if(b[i]==-1){
               // cout<<W<<':'<<L<<endl;
                L++;
            }
    }
    //cout<<i<<'|'<<endl;
    cout<<W<<':'<<L<<endl;
}