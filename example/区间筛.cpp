#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int maxn =1e6+5;
bool isprime[maxn];
bool lowisprime[maxn];
void segment_sieve(long long a,long long b)
{
    for(int i=0;i<1e6+5;i++) isprime[i]=lowisprime[i]=true;
    for(int i=2;(long long )i*i<b;i++)
    {
        if(lowisprime[i])
        {
            for(int j=2*i;(long long)j*j<b;j+=i) lowisprime[j]=false;
            for(long long j=(a/i)*i;j<b;j+=i) if(j>=a&&j<b) isprime[j-a]=false;
        }
    }
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<endl;
    segment_sieve(a,b);
    int cnt=0;
    for(int i=0;i<b-a;i++) if(isprime[i]) cnt++;
    cout<<cnt<<endl;
    return 0;
}