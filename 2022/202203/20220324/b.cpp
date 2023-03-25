#include<iostream>
#include<vector>
typedef unsigned long long ll;
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll tmp,tmp2;
    ll now=1;
    for(int i=1;i<=n;i++){
        cin>>tmp>>tmp2;
        if(tmp>=now)now+=(tmp-now)+tmp2;
        else {
            now+=tmp2;
        }
    }
    cout<<now;
}