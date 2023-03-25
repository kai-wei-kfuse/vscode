#include<iostream>
#include<cstring>
using namespace std;
string a[120];
string x;
int n;
int main()
{   
    cin>>x>>n;
    for(int i=0;i<=n;i++){
        getline(cin,a[i]);
    }
    /*for(int i=0;i<=n;i++){
        cout<<a[i]<<endl;
    }*/
    //cout<<(a[1]==a[n])<<endl;
    bool flag=0;
    for(int i=n,j=1;i>=1;j++,i--){
        if(a[i]!=a[j])flag=1;
    }
    //cout<<flag<<endl;
    if(flag==0){
        cout<<"bu yong dao le"<<endl;
        for(int i=n;i>=1;i--){
            int len=a[i].length();
            //cout<<len;
            for(int j=len-1;j>=0;j--){
                if(a[i][j]==' ')cout<<' ';
                else cout<<x;
            }
            if(i>1)cout<<endl;
        }
    }
    else{
        for(int i=n;i>=1;i--){
            int len=a[i].length();
            //cout<<len;
            for(int j=len-1;j>=0;j--){
                if(a[i][j]==' ')cout<<' ';
                else cout<<x;
            }
            //cout<<'.';
            if(i>1)cout<<endl;
        }
    }
}