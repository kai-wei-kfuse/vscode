#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(x-1>0&&x-y<=1)cout<<"pllj"<<endl;
        else cout<<"freesin"<<endl;
    }
}