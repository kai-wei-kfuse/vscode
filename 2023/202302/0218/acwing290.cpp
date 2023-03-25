#include<bits/stdc++.h>
using namespace std;

const int N = 510;
vector<int> edg[N];
int st[N],match_[N];

int find(int x){
    for(auto i:edg[x]){
        if(!st[i]){
            st[i] = 1;
            if(match_[i]==0||find(match_[i])){
                match_[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m;i++){
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
    }
    int res = 0;
    for (int i = 1; i <= n1;i++){
        memset(st, 0, sizeof st);
        if (find(i)) res++;
    }
    cout << res;
}