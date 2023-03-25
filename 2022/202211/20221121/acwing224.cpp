#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
vector<int> tr(1e5 + 5, 0),ans(1e5+5);
int n;
void add(int i,int x){
    while (i <= n){
        tr[i] += x;
        i += lowbit(i);
    }
}
int query(int i){
    int res = 0;
    while(i){
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}
int main(){
    cin >> n;
    vector<int> ve(n + 1,0);
    add(1, 1);
    for (int i = 2; i <= n;i++){
        cin >> ve[i];
        add(i, 1);
    }
    for (int i = n; i >=1;i--){
        int l = 1, r = n;
        while(l<r){
            int mid = (l + r) / 2;
            if(query(mid)>=ve[i]+1)
                r = mid;
            else
                l = mid + 1;
        }
        add(r, -1);
        ans[i] = r;
    }
    for (int i = 1; i <= n;i++){
        cout << ans[i] << endl;
        
    }
}