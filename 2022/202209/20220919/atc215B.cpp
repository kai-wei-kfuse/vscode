#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll tmp=1;
    ll cnt = 0;
    while (tmp <= n){
        tmp *= 2;
        cnt++;
    }
    cout << cnt-1;
}