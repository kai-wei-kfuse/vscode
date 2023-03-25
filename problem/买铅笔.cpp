#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b,c,d,e,f,i=1,j=1,k=1;
	int sum1,sum2,sum3,num1=0,num2=0,num3=0;
	cin>>n>>a>>b>>c>>d>>e>>f;
	for(;;i++)
		if(i*a>=n){
		num1=i;
		break;
		}
	for(;;j++)
		if(j*c>=n){
			num2=j;
		break;
		}
	for(;;k++)
		if(k*e>=n){
			num3=k;
		break;	
		}
	if(num1*b < num2*d && num1*b < num3*f)cout<<num1*b;
	if(num2*d < num3*f && num2*d < num1*b)cout<<num2*d;
	if(num3*f < num2*d && num3*f < num1*b)cout<<num3*f;
	return 0;
}
