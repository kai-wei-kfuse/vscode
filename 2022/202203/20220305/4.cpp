#include<iostream>
using namespace std;
int main()
{
    string a;
    int x,cnt=0;
    cin>>x;
    cin>>a;
    while(a!="End"){
        if(cnt==x){
            cout<<a<<endl;
            cnt=0;
            cin>>a;
            continue;
        }
        if(cnt<x&&a=="ChuiZi")cout<<"Bu"<<endl;
        if(cnt<x&&a=="Bu")cout<<"JianDao"<<endl;
        if(cnt<x&&a=="JianDao")cout<<"ChuiZi"<<endl;
        cnt++;
        cin>>a;
    }
}