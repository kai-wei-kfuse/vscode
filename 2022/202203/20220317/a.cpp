#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>90 && b>90 && c>60)cout<<"A+"<<endl;
    else cout<<"E+"<<endl;
    }
}