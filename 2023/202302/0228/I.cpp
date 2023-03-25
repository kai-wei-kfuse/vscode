#include<bits/stdc++.h>
using namespace std;

vector<int> dsu(505);
int find(int x){
    while(dsu[x]!=x){
        x = dsu[x] = dsu[dsu[x]];
    }
    return x;
}

void root(int x,int y){
    int x_ = find(x);
    int y_ = find(y);
    if(x_!=y_){
        dsu[x_] = y_;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> edg[n + 5];
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    int t;
    cin >> t;
    vector<int> ve(t+5),vis(n+5,0),ans(t+5,0);
    for (int i = 1; i <= t;i++){
        cin >> ve[i];
    }
    
    for (int i = 1; i <= n;i++){
        dsu[i] = i;
    }
    int now = 0;
    for (int i = t; i >= 1;i--){
        vis[ve[i]] = 1;
       // cout << ve[i] << endl;
        for(auto j:edg[ve[i]]){
            if(vis[j]==1)
            root(ve[i], j);
        }
        int num = 0;
        for (int j = 1; j <= n;j++){
            if(dsu[j]==j&&vis[j]){
                num++;
            }
        }
        if(num<now){
            ans[i] = 1; 
        }
        now = num;
    }
    for (int i = 1; i <= t;i++){
        if(ans[i]){
            cout << "Red Alert: City " << ve[i] << " is lost!" << endl;
        }else{
            cout << "City " << ve[i] << " is lost." << endl;
        }
    }
    if(t==n){
        cout << "Game Over.";
    }
}