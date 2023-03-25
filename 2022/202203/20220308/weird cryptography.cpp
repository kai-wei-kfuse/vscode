#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int cnt=1;
    while(cin>>n,n){
        vector<int > b(n+1);
        map<string,int> mp;
        string a;
        for(int i=1;i<=n;i++){
            cin>>a;
            mp[a]++;
            b[mp[a]]++;
        }
        printf("Case %d: ",cnt++);
        sort(b.begin(),b.end());
        for(int i=1;i<=n;i++){
            if(b[i]){
                cout<<b[i];
            }
        }
        cout<<endl;
    }
}