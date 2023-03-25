#include<iostream>
#include<cstring>
#include<cstdio>
typedef long long ll;
using namespace std;
const ll mod=10007;
ll n;
struct matrix{
    ll m[4][4];
    matrix(){
        memset(m,0,sizeof(m));
        for(int i=0;i<4;i++){
            m[i][i]=1;
        }
    }
};
matrix mul(matrix a,matrix b){
    matrix res;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            res.m[i][j]=0;
            for(int k=0;k<4;k++){
    res.m[i][j]=(res.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    /*for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)cout<<res.m[i][j]<<' ';
        cout<<endl;
    }*/
    //cout<<endl;
    return res;
}
matrix binpow(matrix a,ll n){
    matrix b;
    while(n){
        if(n&1)b=mul(b,a);
        a=mul(a,a);
        n>>=1;
    }
    return b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(!n)cout<<'1';
        else{
        matrix f;
        f.m[0][0]=2,f.m[0][1]=1,f.m[0][2]=1,f.m[0][3]=0;
        f.m[1][0]=1,f.m[1][1]=2,f.m[1][2]=0,f.m[1][3]=1;
        f.m[2][0]=1,f.m[2][1]=0,f.m[2][2]=2,f.m[2][3]=1;
        f.m[3][0]=0,f.m[3][1]=1,f.m[3][2]=1,f.m[3][3]=2;
            /*a.m[0][0] = 2; a.m[0][1]= 1; a.m[0][2] = 0;
            a.m[1][0] = 2; a.m[1][1]= 2; a.m[1][2] = 2;
            a.m[2][0] = 0;a.m[2][1]= 1; a.m[2][2] = 2;*/
        matrix ams=binpow(f,n);
        
        printf("%d\n",ams.m[0][0]);
        }
    }
}
