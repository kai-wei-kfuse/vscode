#include<iostream>
#include<cstring>
using namespace std;
int a[800][800];
int main()
{
    int n;
    cin>>n;
    int x,y;
    while(n--){
        cin>>x>>y;
        char c;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
            cin>>c;
            a[i][j]=c-'0';
            }
        }
        int flag=1;
        for(int i=1;i<x;i++){
            for(int j=1;j<y;j++){
                if(a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1] == 3)flag=0;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;
    }
}