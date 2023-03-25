#include<iostream>//(高精度减)(短)
#include<cstring>
#define maxn 10100
using namespace std;
int A[maxn],B[maxn],C[maxn];
int main()
{
    string a,b;
    cin>>a>>b;
    int lena=a.length();
    int lenb=b.length();
    if(lena<lenb||lena==lenb&&b>a)
	{
		swap(a,b);
		swap(lena,lenb);
		cout<<"-";
	 } 
    for(int i=0;i<lena;i++)
        A[lena-i]=a[i]-'0';
    for(int i=0;i<lenb;i++)
        B[lenb-i]=b[i]-'0';
    for(int i=1;i<=lena;i++)
    {
        if(A[i]<B[i])
        {
            A[i]+=10;
            A[i+1]--;
        }
        C[i]=A[i]-B[i];
    }
    while(C[lena]==0&&lena>1)lena--;
    for(int i=lena;i>0;i--)cout<<C[i];
}
