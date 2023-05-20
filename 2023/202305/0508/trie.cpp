#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;

struct Trie {
    char a[N];
    struct xx {//字典树
        int son[26];//每一个节点都有26个字母，所以是26
      	int tag;//看题目具体情况增加标记
      	//int x;
    } tr[N];
    int idx=0;

    void insert(char a[]) {  
        int p = 0;
        int len=strlen(a);
        for (int i = 0; i < len; i++) {
            int u = a[i]-'a';
            if (!tr[p].son[u]) {
                tr[p].son[u] = ++idx;//如果这个字符没有被存储过，就创建一个节点,idx表示下一个位置，类似于指针
            }
            p = tr[p].son[u];//如果存过了或者创建了，就直接往下走
        }
        tr[p].tag ++;//标记字符串的最后一个字母
    }

    int query(char a[]) {  
        int p = 0;
        int len=strlen(a);
        for (int i = 0; i < len; i++) {
            int u = a[i]-'a';
            if (!tr[p].son[u]) {
                return 0;
            }
            p = tr[p].son[u];
        }
        return tr[p].tag;
    }
};
int main(){
	Trie tr;
    int t;
    cin>>t;
    while(t--){
        char x;
        cin>>x>>tr.a;
        if(x=='I'){
            tr.insert(tr.a);
            //cout<<tr.idx<<endl;
        }else{
            cout<<tr.query(tr.a)<<endl;
        }
    }
}