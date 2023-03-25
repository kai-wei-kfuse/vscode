#include<iostream>
using namespace std;
int main()
{
    int  n;
    cin>>n;
    string a;
    while(n--){
        cin>>a;
        int len=a.length();
        int sum=1,ans=0;
        for(int i=0;i<len;i++){
            if(a[i]=='O'){
                ans+=sum;
                sum++;
            }
            else sum=1;
        }
        cout<<ans<<endl;
    }
}