#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string a[10003];
string b;
int x[10003];
int main()
{
    int n;
    cin>>n;
    
        int tmp=0,cnt=1,len=0;
        while(n>0)
        {
            while(n--){
            cin>>b;
            int flag=0;
            for(int i=1;i<=len;i++){
                //cout<<b<<' '<<a[i];
                if(b==a[i]){
                    x[++tmp]=len;
                    //cout<<tmp<<'|';
                    flag=1;
                }
            }
            if(!flag){
            a[++len]=b;
                }
            else {
                len=0;
                a[++len]=b;
                }
            }
            x[++tmp]=len;
            //cout<<tmp;
            //for(int i=1;i<=tmp;i++)cout<<x[i]<<' ';
        sort(x+1,x+tmp);
        
        cin>>n;
        }
}