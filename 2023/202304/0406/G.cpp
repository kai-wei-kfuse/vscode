#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>x,y;
map<int,int >r;
map<int,int>xxx,yyy;
int main()
{
	int g;
	cin>>g;
	vector<pair<int,int>>ve;
	for(int i=1;i<=g;i++)
	{
		int x,y;
		cin>>x>>y;
		ve.push_back({x,y});	
	}	
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int xx,yy,rr;
		cin>>xx>>yy>>rr;
		xxx[i]=xx,yyy[i]=yy;
		r[i]=rr;
		x[xx].push_back(i);
		y[yy].push_back(i);
	}
	int cnt=0;
	for(auto [u,v]:ve)
	{
		int fg=0;
		map<int,int>mp;
		for(int i=u-100;i<=u+100;i++)
		{
			if(x[i].size()>0)
			{
				for(auto j:x[i])
				{
					if(r[j]>=abs(i-u))
					{
						mp[j]=1;	
					}
				}
			}
		}
		set<int>se;
		for(int i=v-100;i<=v+100;i++)
		{
			if(y[i].size()>0)
			{
				for(auto j:y[i])
				{
					if(r[j]>=abs(i-v))
					{
						if(mp[j]==1)
						{
							mp[j]=2;
							se.insert(j);
						}	
					}
				}
			}
		}
		for(auto it:se)
		{
			if((u-xxx[it])*(u-xxx[it])+(v-yyy[it])*(v-yyy[it])<=r[it]*r[it])
			{
				cnt++;
			}
		}		
	}
	cout<<g-cnt;
	
}