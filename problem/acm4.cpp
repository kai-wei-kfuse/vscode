#include<bits/stdc++.h>//结构体排序
using namespace std;
int b[2][1000001];
struct aaa{
    int x,y;
}a[10000001];
bool cmp(aaa a,aaa b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    cout<<a[i].y<<" ";
}