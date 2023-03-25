#include<iostream>//删数问题
using namespace std;
string n;
int m;
int main()
{
    cin>>n;
    cin>>m;
    int len=n.length();
    int jj;
    while(m--)
    {
        int ii;
        for(int j=0;j<=len-1;j++)
        {
            if(n[j]>n[j+1])
            {
                ii=j;
                break;
            }
        }
        for(int j=ii;j<len-1;j++)
                n[j]=n[j+1];
                n[len-1]='\0';
    }
    n.erase(0,n.find_first_not_of('0'));
    if(!(n[0]-'0'>=0&&n[0]-'0'<=9))
    {
        cout<<"0";
    }
    else
    {
        cout<<n;
        }
    return 0;
}