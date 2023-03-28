#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
struct xx {
    int son[62];
} tr[N];
int idx;
char a[N];

//写一个26字母的字典树模版
inline void insert(char s[]) {
    int p = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int u = s[i] - 'A';
        if (!tr[p].son[u]) {
            tr[p].son[u] = ++idx;
        }
        p = tr[p].son[u];
    }
}

int main(){
    while(cin>>a){
        insert(a);
    }
    cout<<idx+1<<endl;
}
