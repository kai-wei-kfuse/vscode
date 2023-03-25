#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
map< ll , int > mp; 
int main()
{
    int n;
    cin>>n;
    ll tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        mp[tmp]++;
    }
    map<ll ,int  > :: iterator i = mp.begin();
    for(;i != mp.end(); i++){
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }
}