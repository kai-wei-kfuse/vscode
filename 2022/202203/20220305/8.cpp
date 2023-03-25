#include<iostream>
using namespace std;
int a[101][101];
int b[101][101];
int c[101][101];
int main()
{
    int ax,ay,bx,by;
    cin>>ax>>ay;
    for(int i=1;i<=ax;i++){
        for(int j=1;j<=ay;j++){
            cin>>a[i][j];
        }
    }
    cin>>bx>>by;
    if(ay!=bx){
        cout<<"Error: "<<ay<<" !="<<ax<<endl;
        return 0;
    }
    for(int i=1;i<=bx;i++){
        for(int j=1;j<=by;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=ax;i++){
        for(int j=1;j<=by;j++){
            for(int k=1;k<=bx;k++){
                //cout<<a[i][k]<<' '<<b[k][j]<<'|'<<endl;
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    cout<<ax<<' '<<by<<endl;
    for(int i=1;i<=ax;i++){
        for(int j=1;j<=by;j++){
            cout<<c[i][j];
            if(j<by)cout<<' ';
        }
        if(i<ax)
        cout<<endl;
    }
}