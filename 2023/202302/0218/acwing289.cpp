#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int >edge[N];
int col[N];

int dfs(int x,int c){
    col[x] = c;
    for(auto i:edge[x]){
        if(!col[i]){
            if (!dfs(i, 3 - c)) return 0;
        }else if(c==col[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= n;i++){
        if(!col[i]){
            if(!dfs(i,1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes";
}