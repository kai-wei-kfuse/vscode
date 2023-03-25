#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct xx{
    int h,m;
    string s;
}a[1000005];
bool cmp(xx a, xx b){
    return a.h==b.h?a.m<b.m:a.h<b.h;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
        if(a[i].s[0]=='A'){
            //string b=a[i].s.substr(2,a[i].s.find(':')-2);
            //b+=a[i].s.substr(a[i].s.find(':')+1,a[i].s.length());
            int x=0;
            int tmp=a[i].s.find(':');
            int len=a[i].s.length();
            //cout<<tmp<<' '<<len<<endl;
            for(int j=2;j<tmp;j++){
                x=x*10+(a[i].s[j]-'0');
            }
            a[i].h=x;
            int y=0;
            for(int j=tmp+1;j<len;j++){
                y=y*10+(a[i].s[j]-'0');
            }
            a[i].m=y;
            //cout<<x<<':'<<y<<endl;
        }
        else{
            int x=0;
            int tmp=a[i].s.find(':');
            int len=a[i].s.length();
            //cout<<tmp<<' '<<len<<endl;
            for(int j=2;j<tmp;j++){
                x=x*10+(a[i].s[j]-'0');
            }
            a[i].h=x+12;
            int y=0;
            for(int j=tmp+1;j<len;j++){
                y=y*10+(a[i].s[j]-'0');
            }
            a[i].m=y;
            //cout<<x<<':'<<y<<endl;
        }
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        cout<<a[i].h<<":"<<a[i].m<<endl;
    }
}