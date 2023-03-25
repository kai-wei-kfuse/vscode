#include<iostream>
typedef long long ll;
using namespace std;
ll kk[]={9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999};
int main()
{
    int n;
    cin>>n;
    ll m,k;
    while(n--){
        cin>>k>>m;
        if(m%kk[k-1]==0)cout<<"aya"<<endl;
        else cout<<"baka"<<endl;
    }
}