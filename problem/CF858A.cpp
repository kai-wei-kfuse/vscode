#include<iostream>//gcd lcm
//题目要求，求末尾有k个0，即这个数和10的k次方是倍数关系
//又说是n的倍数,也就是求最小公倍数
using namespace std;
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    long long n,k,ten=1;
    cin>>n>>k;
    while(k--)ten*=10;
    cout<<n*ten/gcd(n,ten);
}