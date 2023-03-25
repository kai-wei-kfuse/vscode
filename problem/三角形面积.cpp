#include<bits/stdc++.h>
using namespace std;
int main() 
{
	double a,b,c,p,sum;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	sum=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%0.1f",sum);
	return 0;
}
