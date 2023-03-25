#include<iostream>//高精度减法(自己）
#include<cstring>
#include<algorithm>
#define maxn 10100
int A[maxn],B[maxn],C[maxn];
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int lena=a.length();
    int lenb=b.length();
    for(int i=lena-1;i>=0;i--)//int
    {A[lena-1-i]=a[i]-'0';
        //cout<<A[i-lena+1];
    }
        //cout<<endl;
    for(int i=lenb-1;i>=0;i--)
    {
    B[lenb-1-i]=b[i]-'0';
    //cout<<B[i-lenb+1];
    }
    //cout<<endl;
    int lenc= max (lena,lenb);
    //cout<<lena<<" "<<lenb<<" "<<lenc;
    for(int j=lenc-1;j>=0;j--)
    {
        //cout<<A[i]<<" "<<B[i];
        if(A[j]<B[j])break;
        if(B[j]<=A[j])
        {
            for(int i=0;i<lenc;i++)
            {
                //cout<<A[i]<<" "<<B[i];
                C[i]=A[i]-B[i];
                if(C[i]<0)
                {
                    C[i]=A[i]+10-B[i];
                    A[i+1]--;
                }
            }
            int flag=0;
            for(int i=lenc-1;i>0;i--)
                {
                    if(C[i]!=0)flag=1;
                    if(flag)cout<<C[i];
                }
            cout<<C[0];
            return 0;
        }
    }
    for(int i=0;i<lenc;i++)
            {
                C[i]=B[i]-A[i];
                if(C[i]<0)
                {
                    C[i]=B[i]+10-A[i];
                    B[i+1]--;
                }
            }
    int flag=0;
    cout<<"-";
    for(int i=lenc-1;i>0;i--)
    {
        if(C[i]!=0)flag=1;
        if(flag)cout<<C[i];
    }
    cout<<C[0];
return 0;
}