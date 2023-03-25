#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
    string a,b;
    cin>>a>>b;
    int flag=0;
    int len=a.length();
    for(int i=0;i<len;i+=2){
        if(a[i]==b[0]){
            cout<<"YES"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"NO"<<endl;
}
}