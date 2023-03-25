#include<iostream>//矩阵快速幂模板(函数版)
#include<cstring>
typedef long long ll;
using namespace std;
/*
矩阵快速幂：
1、矩阵结构体
2、初始化单位矩阵
3、输入矩阵
4、矩阵乘法函数
5、快速幂
6、输出
*/
ll n,p;
const ll mod= 1e9 +7;
ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
struct matrix{
    ll a[105][105];
    matrix(){
        memset(a,0,sizeof(a));
    }
}a;
matrix mul(matrix a,matrix b){
    matrix res;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                res.a[i][j]=(res.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
            }
        }
    }
    return res;
}
matrix fpow(matrix a,ll n, ll p){
    matrix res;
    for(int i=1;i<=n;i++)
        res.a[i][i]=1;
    while(p){
        if(p&1)res=mul(a,res);
        a=mul(a,a);
        p>>=1;
    }
    return res;
}
int main()
{
    n=read();
    p=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a.a[i][j]=read();
        }
    }
    matrix ans=fpow(a,n,p);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",ans.a[i][j]);
        }
        printf("\n");
    }
}