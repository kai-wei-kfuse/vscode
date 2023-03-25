#include<iostream>
using namespace std;
int main()
{
    //typedef long long long long;
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long x;
        long long asum=0;
        long long bsum=0;
        for(int i=1;i<=n;i++){
            cin>>x;
            if(x%2==0)bsum+=(x/2)-1;
            else asum+=x/2+1;   
        }
        if(asum>bsum)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}