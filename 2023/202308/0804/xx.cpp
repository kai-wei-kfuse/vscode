#include <algorithm> // max
#include <cassert>   // assert
#include <cstdio>    // printf,sprintf
#include <cstring>   // strlen
#include <iostream>  // cin,cout
#include <string>    // string类
#include <vector>    // vector类
using namespace std;
using ll = long long;
void write(__int128 n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    if (n/10) write(n/10);
    putchar(n%10+'0');
}

int main()
{

        for(int n=1;n<=1000;n++)
        {
                int cc=0;
                int aa=0,bb=0;
                for(int i=n;i>=1;i--)
                {
                    for(int j=i;j>=1;j-=2)
                    {
                        if(j%10==0) cc+=j/10;
                        else if(j%5==0) aa++;
                        else if(j%2==0) bb++;
                    }
                }
                /* cout<<cc+min(aa,bb)<<endl; */
                __int128 dec=n/10;
                __int128 x,y;
                if(n&1)
                {
                    x=n/2;
                    y=n/2+1;
                }else
                {
                    x=n/2;
                    y=n/2;
                }

                __int128 dd=n/5-n/10;
                __int128 ans=0;
                if(dec>0)
                {
                    __int128 sum=dec*x-(__int128(5)*dec+__int128(3))*dec/2;
                    
               
                    ans+=sum;
                }
                
                if(dd>0)
                {
                    __int128 ssum=dd*y-(__int128(5)*dd-__int128(1))*dd/2;
                    
                   
                    ans+=ssum;
                }
                if(cc+min(aa,bb)!=ans)
                {
                    cout<<n<<" "<<cc+min(aa,bb)<<' ';
                    write(ans);
                    cout<<endl;
                }
        }
            
        
   
}