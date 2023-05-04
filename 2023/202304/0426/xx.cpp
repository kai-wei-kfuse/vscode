#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct Suffix{
	int ht[N],rk[N],sa[N],y[N],c[N];
    int n,m;
    char s[N];
	void init(){
        n=strlen(s+1);
        m=300;
		for(int i=0;i<=m;i++) c[i]=0;
		for(int i=0;i<=2*n;i++) y[i]=0;
		for(int i=1;i<=n;i++) c[rk[i]=s[i]]++;
		for(int i=1;i<=m;i++) c[i]+=c[i-1];
		for(int i=n;i>=1;i--) sa[c[rk[i]]--]=i;
		for(int k=1;k<=n;k<<=1){
			int p=0;
			for(int i=n-k+1;i<=n;i++) y[++p]=i;
			for(int i=1;i<=n;i++){
				if(sa[i]>k){
					y[++p]=sa[i]-k;
				}
			} 
			for(int i=0;i<=m;i++) c[i]=0;
			for(int i=1;i<=n;i++) c[rk[i]]++;
			for(int i=1;i<=m;i++) c[i]+=c[i-1];
			for(int i=n;i>=1;i--) sa[c[rk[y[i]]]--]=y[i];
			for(int i=0;i<=n;i++) swap(rk[i],y[i]);
			rk[sa[1]]=p=1;
			for(int i=2;i<=n;i++){
				rk[sa[i]]=(y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p : ++p);
			}
			if(p>=n) break;
			m=p;
		}
		for(int i=1,k=0;i<=n;i++){
			if(k)k--;
			int j=sa[rk[i]-1];
			while(s[i+k] == s[j+k] )k++;
			ht[rk[i]] = k;
		}
	}
    void writ()
    {
        printf("%s\n",s+1);
        for(int i=1;i<=n;i++)cout<<sa[i]<<" ";;cout<<"\n";
        for(int i=1;i<=n;i++)cout<<ht[i]<<" ";;cout<<"\n";
        for(int i=1;i<=n;i++)cout<<rk[i]<<" ";;cout<<"\n";
    }
    
};
Suffix suf;
int st[20][N];
void init()
{
    int n=strlen(suf.s+1);
    for(int i=1;i<=n;i++)st[0][i]=suf.ht[i];
    for(int j=1;j<20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++)st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    }
}
int get(int l,int r){
    // cout<<"l="<<l<<" r="<<r<<"\n";
    int g=std::__lg(r-l+1);
    return min(st[g][l],st[g][r-(1<<g)+1]);
}
int solve()
{
    int n,m;
    scanf("%s",suf.s+1);
    n=strlen(suf.s+1);
    suf.s[n+1]='#';
    scanf("%s",suf.s+n+2);
    m=strlen(suf.s+n+2);
    suf.init();
    init();
    int ans=0;
    vector<int> A(n);
    for(int i=1;i<=n;i++)A[i-1]=suf.rk[i];
    sort(A.begin(),A.end());
    for(auto i:A){
        cout<<i<<' ';
    }
    cout<<endl;
    for(int i=1;i<=m;){
        int Rk=suf.rk[n+1+i];
        int mx=0;
        auto it=lower_bound(A.begin(),A.end(),Rk);
        if(it!=A.end()){
            mx=max(mx,get(Rk+1,*it));
        }
        if(it!=A.begin()){
            it--;
            mx=max(mx,get(*it+1,Rk));
        }
        ans++;
        assert(mx>0);
        i+=mx;
    }
    suf.writ();
    return ans;
}
int main()
{
    int T;scanf("%d",&T);while(T--)printf("%d\n",solve());
    return 0;
}
/*jzq$jzqjzq
3 6
10 3 7 0 4 9 2 6 8 1 
3 9 6 1 4 10 7 2 8 5 
0 0 0 3 3 0 1 1 0 2 
1
abcd$dcbadcba
4 8
13 4 12 0 8 11 7 1 10 6 2 3 9 
3 7 10 11 1 13 9 6 4 12 8 5 2 
0 0 0 1 1 0 2 1 0 3 1 0 1 
2
aabaaabaaaab$aabaaaaaba
12 10
23 12 22 16 7 17 8 18 3 9 19 13 4 0 10 20 14 5 1 11 21 15 6 
13 18 23 8 12 17 22 4 6 9 14 19 1 11 16 21 3 5 7 10 15 20 2 
0 0 0 1 4 5 3 4 5 2 3 4 7 6 1 2 3 6 5 0 1 2 5 
2
*/