#include<bits/stdc++.h>
using namespace std;

vector<int> dsu1(100 + 1), dsu2(100 + 1);
int find1(int x){
    while(dsu1[x]!=x){
        x = dsu1[x] = dsu1[dsu1[x]];
    }
    return x;
}


void root1(int x,int y){
    int x_ = find1(x);
    int y_ = find1(y);
    if(x_!=y_){
        dsu1[x_] = y_;
    }
}


int main(){
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int,int>, int> mp;
    for (int i = 1; i <= n;i++){
        dsu1[i] = i;
        dsu2[i] = i;
    }
        for (int i = 1; i <= m; i++) {
            int x, y, tmp;
            cin >> x >> y >> tmp;
            if (x > y) swap(x, y);
            mp[{x, y}] = tmp;
            if(tmp==1){
                root1(x, y);
            }
        }
        for (int i = 1; i <= k;i++){
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            if(mp[{x,y}]==1){
                cout << "No problem" << endl;
            }else if(mp[{x,y}]==0){
                cout << "OK" << endl;
            }else{
                if(find1(x)==find1(y)){
                    cout << "OK but..." << endl;
                }else{
                    cout << "No way" << endl;
                }
            }
        }
}