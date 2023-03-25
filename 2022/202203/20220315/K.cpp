#include<iostream>
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        ll sum=0;
        for(int i=1;i<=x;i++){
            sum+=i*i*y;
        }
        cout<<sum<<endl;
    }
}