#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string a;
    cin>>a;
    for(int i=6;i<10;i++)cout<<a[i];
    cout<<'-';
    for(int i=0;i<5;i++)cout<<a[i];
}