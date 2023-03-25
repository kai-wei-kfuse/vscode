#include<bits/stdc++.h>
using namespace std;
int main()
{
	string e,f,w;
	getline(cin,e);
    getline(cin,w);
    w=w+' ';
    e=e+' ';
    int sum=0,j=0,num=0,first=0,len=w.length();
    for(int i=0;i<len;i++)
    {
    	if(tolower(e[j])!=tolower(w[i])){
    		while(w[i]!=' '&&w[i+1]!=' ')i++;
    		j=0;
    		continue;
		}
    	else if(w[i]==' ')
    	{
			num++;
			if(num==1)first=i-e.length()+1;
			j=0;
			continue;
		}
		j++;
    }
    if(num==0)cout<<"-1";
    else cout<<num<<' '<<first;
    return 0;
}