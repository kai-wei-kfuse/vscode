#include<bits/stdc++.h>
using namespace std;
int f(int l,int r,int x) { // l <= x <= r
    int cnt = 0;
    while(l <= r) {
        cnt++;
        int mid = (l + r) / 2;
        if (mid == x) break;
        if (mid < x) l = mid + 1;
        else r = mid - 1;
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        cout<<f(l,r,x)<<endl;
    }
}