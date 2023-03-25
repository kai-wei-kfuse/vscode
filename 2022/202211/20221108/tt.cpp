#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> tr(500005);
int lowbit(int x){
    return x & (-x);
}
void add(int i,int x){
    while(i<=n){
        tr[i] += x;
        i += lowbit(i);
    }
}
int query(int i){
    int res = 0;
    while(i>0){
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}
int main(){
    int k;
    cin >> n >> k;
    int tmp;
    for (int i = 1; i <= n;i++){
        cin >> tmp;
        add(i, tmp);
    }
    int a, b, c;
    while(k--){
        cin >> a >> b >> c;
        if(a==1){
            add(b, c);
        }else{
            cout << query(c) - query(b - 1) << endl;
        }
    }
}