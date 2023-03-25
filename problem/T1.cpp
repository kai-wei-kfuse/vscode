#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	char a[100];
	gets(a);
	int b=strlen(a);
	for(int i=0;i<b;i++)
	{
		if(a[i]!=' ')cout<<a[i];
	}
	return 0;
}

