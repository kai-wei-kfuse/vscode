#include<bits/stdc++.h>
using namespace std;

vector<int> dsu(10000 + 1),app(10000,0x3f3f3f3f);
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
        if (x_ < y_) swap(x_, y_);
        dsu[x_] = y_;
        app[y_] = min(x_, app[y_]);
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++){
        dsu[i] = i;
    }
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        root(x, y);
    }

    for (int i = 1; i <= k;i++){
        int x;
        cin >> x;
        //cout << find(x) << endl;
        if(find(x)==x&&app[x]==0x3f3f3f3f){
            cout << "0" << endl;
        }else{
            if(find(x)!=x)
            cout << find(x) << endl;
            else
            cout << app[x] << endl;
        }
    }
}