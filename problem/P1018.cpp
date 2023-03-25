#include<iostream>
#include<cstring>
using namespace std;
string a,b;
string dp[42][7];
int A[42],B[42],C[42];
string mul(string a,string b)
{
    //cout<<a<<'*'<<b<<'=';
    string ans;
    memset(C,0,sizeof(C));
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    int lena=a.length();
    int lenb=b.length();
    int len=lena+lenb;
    for(int i=lena-1;i>=0;i--)
        A[lena-i]=a[i]-'0';
    for(int i=lenb-1;i>=0;i--)
        B[lenb-i]=b[i]-'0';//和高精加一样，把字符转为int数组，
        //同样要倒过来字符数组最高位是个位，把他变成int数组第一位
    for(int i=1;i<=lena;i++)
        for(int j=1;j<=lenb;j++)
        C[i+j-1]+=A[i]*B[j];//这里开始乘，根据乘法运算，要两数的每个数枚举相乘，而且
        //规律是第i位和第j位相乘，得到的数在i+j-1处
    for(int i=1;i<=len;i++)
    {
        C[i+1]+=C[i]/10;
        C[i]%=10;//和高精加一样，模拟进位
    }
    //string ans;
    while(!C[len])len--;
    for(int i=max(len,1);i>0;i--){//为了防止乘数是零，如果是0，len就变成零了
        ans+=C[i]+48;
        }
    //cout<<"("<<ans<<")"<<' ';
    return ans;
}
string turn(int f,int l)
{
    string cmp;
    while(f<=l){
        cmp+=a[f];
        f++;
    }
    return cmp;
}
string maxn(string a,string b)
{
    if(a.size()!=b.size())return a.size()>b.size()?a:b;
    return a>b?a:b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    //for(int i=1;i<=n;i++)
        cin>>a;
    for(int i=1;i<=n;i++){
        dp[i][0]=turn(0,i-1);
        //cout<<dp[i][0]<<' ';
        for(int j=1;j<=m;j++){
            for(int k=1;k<i;k++){
                //cout<<dp[i][j]<<'|'<<' ';
                dp[i][j]=maxn(dp[i][j],mul(dp[k][j-1],turn(k,i-1)));
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[n][m];
    //mul(a,b);
    return 0;
}