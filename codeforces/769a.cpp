#include<iostream>
#include<cstring>
using namespace std;
string a;
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        cin>>a;
            if(m>=3)cout<<"NO"<<endl;
            else if(a[0]==a[1])cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
    }

}