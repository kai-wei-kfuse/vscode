#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAX_NODE = 1000000 + 10;
const int CHARSET = 26;
int trie[MAX_NODE][CHARSET] = {0};
int color[MAX_NODE] = {0};
int k = 1;

void insert(char *w){
    int len = strlen(w);
    int p = 0;
    for(int i=0; i<len; i++){//遍历字符串
        int c = w[i] - 'a';//转int
        if(!trie[p][c]){
            trie[p][c] = k;
            k++;
        }
        p = trie[p][c];
    }
    color[p] = 1;
}

int search(char *s){
    int len = strlen(s);
    int p = 0;
    for(int i=0; i<len; i++){
        int c = s[i] - 'a';
        if(!trie[p][c]) return 0;
        p = trie[p][c];
    }
    return color[p] == 1;
}

int main(){
    int t,q;
    char s[20];
    scanf("%d%d", &t,&q);
    while(t--){
        scanf("%s", s);
        insert(s);
    }
    while(q--){
        scanf("%s", s);
        if(search(s)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}