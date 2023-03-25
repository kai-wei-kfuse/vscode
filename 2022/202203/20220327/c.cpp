#include<iostream>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin>>n;
    int tmp;
    while(n--){
        cin>>tmp;
        if(tmp==1){
            cin>>a[1];
            if(a[1]==1)
            cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            }
            else{
                int flag=1;
                cin>>a[1];
        for(int i=2;i<=tmp;i++){
            cin>>a[i];
            //if(a[i]==a[i-1]-2 && a[i]!=1)flag=0;
             if(a[i-1]==1 && a[i]!=2)flag=0;
            else if(a[i-1]==tmp && a[i]!=1)flag=0;
            else if(a[i]-a[i-1]>=2)flag=0;
            else if(a[i]>tmp)flag=0;
            }
            if(flag)
            cout<<"YES"<<endl;
            else 
            cout<<"NO"<<endl;
        }
    }
}