#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
int a[100105];
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    while(n--){
        int x,p;
        cin>>x>>p;
        vector<int>a(x);
        for(int i=1;i<=x;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        for(int i=1;i<=p;i++){
            int w;
            cin>>w;
            if(w==1){
                
            }
        }
    }
}