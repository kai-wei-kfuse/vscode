#include<iostream>
#include<vector>
using namespace std;
vector<int >a[10005];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int k;
    cin>>k;
    while(k--){
        int c;
        cin>>c;
        for(int i=1;i<=c;i++){
            
        }
    }
}