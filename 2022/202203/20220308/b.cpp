#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int l,r,a;
        cin>>l>>r>>a;
            /*if(r%a==0)cout<<(r-1)/a+a-1<<endl;
            else if((r+1)%a==0)cout<<r/a+a-1<<endl;
            else if(r%a!=0&&r-r%a>=l){
            cout<<((r/a)*a-1)/a+a-1<<endl;}
            else 
            cout<<r/a+r%a<<endl;*/
            int maxx=r/a+r%a;
            int m = (r/a)*a-1;
            if(m >= l)maxx = max(maxx,m/a+m%a);
            cout<<maxx<<endl;
    }
}
