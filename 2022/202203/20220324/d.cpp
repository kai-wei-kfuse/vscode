#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2==0){
        cout<<n/2+1<<endl;
        for(int i=1;i<=n;i+=2){
            cout<<i<<' ';
        }
        cout<<n;
    }
    else {
        cout<<n/2+1<<endl;
        for(int i=1;i<=n;i+=2){
            cout<<i<<' ';
        }
    }
}