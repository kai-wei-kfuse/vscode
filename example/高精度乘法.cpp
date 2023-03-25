#include<iostream>//高精度乘法
#include<cstring>
using namespace std;
string x,y;
int a[1000005],b[1000005],c[1000005],lena,lenb ,lenc;
int main()
{
    cin >> x >> y;
    lena = x.length();
    lenb = y.length();
    for(int i = 0; i < lena;i ++)
        a[lena - i] = x[i] - '0';
    
    for(int i = 0; i < lenb ; i ++)
        b[lenb - i] = y[i] - '0';
    
    for(int i = 1; i <= lena; i++){
        for(int j = 1; j <= lenb; j++)
        {
            c[i+j-1] += a[i] * b[j];
            c[i+j] +=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
    }
    lenc = lena + lenb;
    while(c[lenc]==0 && lenc > 1)lenc--;
    for(int i=lenc;i>=1;i--){
        cout<<c[i];
    }
}