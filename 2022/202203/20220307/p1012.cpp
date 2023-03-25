#include<iostream>
using namespace std;
string a[25];
int vis[25];
int n;
int cnt=1;
void find()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
                if(a[j]+a[j+1]<a[j+1]+a[j]){
                    //cout<<a[j]<<' '<<a[j+1]<<' '<<bijiao(a[j],a[j+1])<<endl;
                    string tmp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=tmp;
                }
            }
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<a[i]<<'|';
    }
    find();
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
}   