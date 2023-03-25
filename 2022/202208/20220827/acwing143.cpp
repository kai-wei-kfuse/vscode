#include<iostream>
#include<algorithm>
using namespace std;

const int m = 100005,mm=3100005;
int n, idx, son[mm][2],a[m];

void insert(int x){
    int p = 0;
    for (int i = 30; ~i;i--){//~i等价于i>=0
        int& s = son[p][x >> i & 1];//&引用
        if(!s)
            s = ++idx;
        p = s;
    }
}

int search(int x){
    int p = 0, res = 0;
    for (int i = 30; ~i;i--){
        int s = x >> i & 1;
        if(son[p][!s]){
            res += 1 << i;
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    return res;
}

int main(){
    cin>>n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 1; i <= n;i++){
        res = max(res, search(a[i]));
    }
    cout<<res<<'\n';
}