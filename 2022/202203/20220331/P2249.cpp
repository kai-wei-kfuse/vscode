#include<iostream>
using namespace std;
int a[1000005];
int main()
{
    int n,t;
    cin >> n >> t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int tmp;
    while(t--){
        cin>>tmp;
        int l=0,r=n+1,mid;
        while(l+1!=r){
            mid = l+(r-l)/2;
           //cout<<mid<<endl;
            if(a[mid] < tmp)
                l=mid;
            else
                r=mid;
        }
        if(a[r]==tmp){
            cout<<r<<' ';
        }
        else cout<<"-1"<<' ';
    }
}