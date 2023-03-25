void fuc(int n,int m){
int ans = n;  // C(n,1) = n;
for(int i = 2;i <= m;i++)//快速求出组合数C
    ans = ans * (n - i + 1) / i;   // C(n,i) = ans;
}