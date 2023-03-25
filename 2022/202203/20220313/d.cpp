#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int t,ans=0;
        cin>>t;
        int tmp;
        for(int i=1;i<=t;i++){
            cin>>tmp;
            if(tmp)ans++;
        }
        cout<<ans<<endl;
    }
}