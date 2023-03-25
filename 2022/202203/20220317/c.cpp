#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
priority_queue <int ,vector<int >,greater<int > >q;
int a[2];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        q.push(tmp);
    }
    while(q.size()>1){
        int x,y;
        x=q.top();q.pop();
        //y=q.top();q.pop();
        if(q.top()-x<=k){
            continue;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}