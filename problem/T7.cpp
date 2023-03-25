#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,l,k;
	cin>>n;
	if(n%2!=0)cout<<"wo bu fang";
	else{
	k=sqrt(n);
	if(k %2!=0)
		{
		l=n*2;
		m=sqrt(l);
		if(m%2==0)cout<<"wo hen fang";
		}
	else 
	{
		m=sqrt(n);
		if(m%2==0)cout<<"wo hen fang";
	}
	}
	return 0; 
}
