#include<iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int sum=0;
    sum+=a[0]-'0';
    for(int i=2;i<=4;i++){
        sum+=(a[i]-'0')*i;
    }
    for(int i=6;i<=10;i++){
        sum+=(a[i]-'0')*(i-1);
    }
    //cout<<sum<<endl;
    if(sum%11==10 && a[12]!='X'){
        for(int i=0;i<12;i++){
        cout<<a[i];
    }
    cout<<'X';
    return 0;
    }
    else if(sum%11==10 && a[12]=='X')cout<<"Right";
    else if(sum%11==a[12]-'0')cout<<"Right";
    else {
    for(int i=0;i<12;i++){
        cout<<a[i];
    }
    cout<<sum%11;
    }
}