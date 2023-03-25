#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[] = {0,     1,       10,       100,       1000,
           100000, 1000000, 10000000, 100000000, 1000000000};
int main()
{
    int n;
    cin >> n;
    ll tmp, ans;
    while(n--){
        cin >> tmp;
        ll x = 1;
        while(x<tmp){
            x *= 10;
        }
        if(x>tmp)
            x /= 10;
        cout << tmp - x << "\n";
    }
}