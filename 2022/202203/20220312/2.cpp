#include<iostream>
#include<string>
using namespace std;
int a[7];
int s,n;
int main()
{
    cin>>s>>n;
    for(int i=1;i<=s;i++){
        a[i]=26;
    }
    int m=1;
    for(int i=1;i<=s;i++)
    cout<<a[i];
}