#include<iostream>//树状数组
using namespace std;
int a[500005],tree[500005];
int t,x,y,z,n,m;
int lowbit(int x){
    return x&(-x);
}
void add(int i,int k){
    while(i<=n){
        tree[i]+=k;
        i+=lowbit(i);
    }
}
int search(int i){
    int sum=0;
    while(i!=0){
        sum+=tree[i];
        i-=lowbit(i);
    }
    return sum;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(m--){
        scanf("%d",&t);
        if(t==1){
            scanf("%d %d %d",&x,&y,&z);
            add(x,z);
            add(y+1,-z);
        }
        else if(t==2){
            scanf("%d",&x);
            cout<<a[x]+search(x)<<endl;
        }
    }
}