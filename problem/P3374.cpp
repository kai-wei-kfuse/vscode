#include<iostream>//树状数组
using namespace std;
//int p[500005];
int n,m,tree[500005];//n数的个数
int lowbit(int x){
    return x&(-x);
}
void add(int i,int a){//单点增加
    while(i<=n){
        tree[i]+=a;
        i+=lowbit(i);
    }
}
int search(int i){//前缀和查询
    int ans=0;
    while(i!=0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}
int main()
{ 
    int a,b,c;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%d",&tmp);
        add(i,tmp);
    }
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            add(b,c);
        }
        else if(a==2){
            cout<<search(c)-search(b-1)<<endl;
        }
    }
}