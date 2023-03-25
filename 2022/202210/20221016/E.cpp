#include<bits/stdc++.h>
using namespace std;
vector<int> ve(55),up(55),down(55);
int ans;
int n;

void dfs(int u,int d,int t){
    if(u+d>=ans)
        return;
    if(t==n+1){
        ans = u + d;
    }
    int i;
    for (i = 1; i <= u;i++){
        if(ve[t]<up[i])
            break;
    }
    int tmp = up[i];
    up[i] = ve[t];
    dfs(max(u,i), d, t + 1);
    up[i] = tmp;
    for (i = 1; i <= d;i++){
        if(ve[t]>down[i])
            break;
    }
    tmp = down[i];
    down[i] = ve[t];
    dfs(u, max(d,i), t + 1);
    down[i] = tmp;
}
int main(){
    
    while(cin>>n,n){
        for (int i = 1; i <= n;i++){
            cin >> ve[i];
        }
        ans = n;
        dfs(0, 0, 1);
        cout << ans << endl;
    }
}