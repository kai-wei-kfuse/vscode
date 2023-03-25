#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
ll mins = 0x3f3f3f;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
ll a[5000015];
int main()
{
    int n;
    cin>>n;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
        cout<<i<<' '<<a[i-1]<<endl;
        mins = min(a[i],mins);
        cout<<mins<<endl;
    }
    if(mins>=0)cout<<"0";
    else cout<<(-mins);
}