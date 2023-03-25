#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int a[200002],b[200002];
int ans= 0x80000000;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    deque < int > Q;
    Q.push_back(0);
    for(int i=1;i<=n;i++){
        while(!Q.empty() && Q.front()+m<i)Q.pop_front();
        while(!Q.empty() && b[Q.back()]>b[i])Q.pop_back();
        ans=max(ans,b[i]-b[Q.front()]);
        Q.push_back(i);
    } 
    cout<<ans;
}