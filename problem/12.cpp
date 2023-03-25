#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define LL long long
using namespace std;
struct squ{int x,y;LL w[4][4];}base={1,3,{{},{0,1,1,1}}},acc={3,3,{{},{0,1,1,1},{0,0,1,1},{0,1,1,2}}},ans;
int t,n;
void multi(squ &c,squ a,squ b)
{
	c.x=a.x;c.y=b.y;
	memset(c.w,0,sizeof(c.w));
	for(int i=1;i<=c.x;i++)
	for(int j=1;j<=c.y;j++)
	for(int k=1;k<=a.y;k++)
	c.w[i][j]=(c.w[i][j]+a.w[i][k]*b.w[k][j])%mod;
	return;
}
squ ksm(int k)
{
	if(k==1) return acc;
	squ tmp=ksm(k/2),sum;
	multi(sum,tmp,tmp);
	if(k%2) multi(sum,sum,acc);
	return sum;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			case 2:
			case 3:printf("1\n");break;
			default:{
				multi(ans,base,ksm((n-1)/3));
				int x=n%3;if(!x) x=3;
				printf("%d\n",ans.w[1][x]);
				break;
			}
		}
	}
	return 0;
}