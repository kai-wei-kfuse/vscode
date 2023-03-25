#include<iostream>
#include<algorithm>
using namespace std;
int a[502];
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int f=0,l=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=i){
                f=i;
                break;
            }
        }
        //cout<<f<<'|';
        if(f!=0){
        for(int i=1;i<=n;i++){
            if(a[i]==f){
                l=i;
                break;
            }
        }
        //cout<<l<<'|';
        int L=f,R=l;
        //cout<<L<<' '<<R<<'|';
        for(int i=0;i<=(R-L)/2;i++){
            int cmp=a[L+i];
            a[L+i]=a[R-i];
            a[R-i]=cmp;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
}