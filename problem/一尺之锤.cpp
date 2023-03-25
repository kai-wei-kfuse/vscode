#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,i=1;
	cin>>a;
	int n=a;
	while(n!=1)
	{
		n=n/2;
		i++;
	}
	cout<<i;
	return 0;
 } 
