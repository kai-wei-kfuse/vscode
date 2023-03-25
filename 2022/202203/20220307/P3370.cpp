#include<iostream>
#include<vector>
using namespace std;
char a[1510];
#define base 261
#define mod 23333
vector <string > Hash[mod+2];
int ans;
inline void insert(){
    int hashs=1;
    for(int i=0;a[i];i++){
        hashs=(hashs*1ll*base+a[i])%mod;
    }
    string t=a;
    for(int i=0;i<Hash[hashs].size();i++){
        if(Hash[hashs][i]==t){
            return ;
        }
    }
        Hash[hashs].push_back(t);
        ans++;
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        insert();
    }
    cout<<ans;
}