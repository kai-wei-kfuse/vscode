#include <iostream>
#include <string.h>
using namespace std;
int n,num=2;
long long answer[10000000];
int main()
{
 memset(answer,0,sizeof(answer));
 answer[4]=1;
 int t;
 cin>>t;
 for(int i=1;i<=t;++i)
 {
  cin>>n;
  if(answer[n]!=0)
  {
   cout<<answer[n]%(1000000007)<<endl;
  }
  else
  {
   for(int i=4;i<=n;++i)
   {
    if(answer[i]!=0)continue;
    else
    {
     answer[i]=answer[i-1]+(i-3);
    }
   }
   cout<<answer[n]%(1000000007)<<endl;
  }
 }
 return 0;
}