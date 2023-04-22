#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef unsigned long long ull;
const int N = 1000010, P = 131;
int n, len;
string s, x;
// ull mod = 212370440130137957 或 1<<30,或者可以写双哈希，进制数131差不多了
ull mod = 212370440130137957;
// p[i]=P^i, h[i]=s[1~i]的hash值
ull p[N], h[N];

// 预处理 hash函数的前缀和
void init() {
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= len; i++) {
        p[i] = (__int128)p[i - 1] * P % mod;
        h[i] = ((__int128)h[i - 1] * P % mod + (ull)x[i]) % mod;
    }
}
// 计算s[l~r]的 hash值
ull get(int l, int r) {
    return (((__int128)h[r] - (__int128)h[l - 1] * p[r - l + 1] % mod) % mod +
            mod) %
           mod;
}


int main() {
    IOS cin >> n;
    map<ull,bool>mp1;
    map<ull,bool>mp2;
    for(int i=1;i<=n;i++){
        cin>>x;
        len=x.size();
        x=" "+x;
        init();
        mp1[h[x.size()]]=1;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        len=x.size();
        x=" "+x;
        init();
        mp2[h[x.size()]]=1;
    }
    cin>>x;
    x=" "+x;
    init();
    int len=x.size();

}