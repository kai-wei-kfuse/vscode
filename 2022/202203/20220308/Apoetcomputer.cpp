#include<iostream>//字典树
#include<cstring>
#include<algorithm>
int tr[100005][27];
int w[100005];
int idx,res,cnt;
using namespace std;
int turn(char s){
    //cout<<s<<endl;
    if(s>='a'&&s<='z')
        return s-'a';
    else return s-'A';
}
void insert(char *s){
    int len=strlen(s+1);
    int p=1;
    for(int i=len;i>=1;i--){
    int x=turn(s[i]);
        if(!tr[p][x])
            tr[p][x]=++idx;
        p=tr[p][x];//
        w[p]++;//记录到这里有多少个单词相同的
    }
}
void dfs(int u,int len){
    if(len>res && w[u]>=3){
        res=len;
        cnt=w[u];
    }
    else if(len==res && w[u]>=3){
        cnt=max(cnt,w[u]);
    }
    for(int i=0;i<26;i++){
        if(tr[u][i]){
            dfs(tr[u][i],len+1);
        }
    }
}
int main()
{
    int n;
    int cases=1;
    scanf("%d", &n);
    while(n--){
        char s[105];
        memset(tr,0,sizeof(tr));
        memset(w,0,sizeof(w));
        idx=1;res=0;cnt=0;
        int t;
        scanf("%d",&t);
        for(int i=1;i<=t;i++){
            scanf("%s",s+1);
            insert(s);
        }
        dfs(1,0);
        if(res==0){
            printf("Case %d:\n",cases++);
            printf("0 %d\n",t);
        }
        else{
            printf("Case %d:\n",cases++);
            printf("%d %d\n",res,cnt);
        }
    }
}