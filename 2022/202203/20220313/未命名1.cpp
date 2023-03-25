#include<iostream>
#include<cstring>
using namespace std;
#define maxn 1000010
int kmp[maxn],lena,lenb;
char a[maxn],b[maxn];
int main()
{
	cin>>a+1;
	cin>>b+1;
	lena = strlen(a+1);
	lenb = strlen(b+1);
	kmp[1] = 0;
	for(int i = 1,len = 0; i <= lena; i++){
		while(len > 0 && a[i] != a[len + 1])len = kmp[len];
		if(a[i] == a[len + 1])len ++;
		kmp[i]=len;
	}
	for(int i = 1,len = 0;i <= lenb; i++){
		while(len > 0 && (len == lena || b[i] != a[len + 1]))len = kmp[len];
		if(b[i] == a[len + 1])len ++;
		if(len == lena)cout<<i- len +1<<endl;
	}
	for(int i=1;i<=lena;i++{
		cout<<kmp[i]<<' ';
}
