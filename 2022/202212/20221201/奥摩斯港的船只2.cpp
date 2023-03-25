#include<stdio.h>
struct tab
{
	int t;
	int i; 
}a[1000005];
int num[1000005]={0};
int time[10000005]={0};
int main()
{
	int N=0,x=0;
	int T=0;
	scanf("%d",&T);
	while(N+x<T)
	{
		int q=0,t,i;
		scanf("%d",&q);
		if(q==1){
			scanf("%d%d",&t,&i);
			num[i]++;
			if(num[i]%2==1)
			{
				a[x].t=t;
			}
			else
			{
				a[x].t=-1;
			}
			//printf("t=%d i=%d\n",a[x].t,i);
			
			
			x++;
		}
		else
		{
			scanf("%d",&time[N]);
			N++;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		int ans=0;
		for(int j=0;j<x;j++)
		{
			if(a[j].t>=0&&a[j].t<=time[i])
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
