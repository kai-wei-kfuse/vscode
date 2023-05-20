#include<bits/stdc++.h>
using namespace std;

// struct Hash {//下标从0开始
//     const long long mod1 = 1e12+39;
//   	const long long mod2 = 998244353;
//     const int P = 13331;
//     vector<long long> h1, p1, h2 ,p2;
//     Hash(string s) : h1(s.size() + 1), p1(s.size() + 1), h2(s.size() + 1), p2(s.size() + 1) {//初始化构造函数，s表示参数,冒号后面表示需要初始化的成员变量
//         int n = s.size();
//         p1[0] = 1;
//         p2[0] = 1;
//         for (int i = 0; i < n; i++) {
//             h1[i + 1] = (h1[i] * P + s[i]) % mod1;
//             h2[i + 1] = (h2[i] * P + s[i]) % mod2;
//             p1[i + 1] = p1[i] * P % mod1;
//             p2[i + 1] = p2[i] * P % mod2;
//         }
//     };

//     long long get1(int l, int r) {
//         return (h1[r+1] + __int128(h1[l]) * (mod1 - p1[r + 1 - l])) % mod1;
//     };
//     long long get2(int l, int r) {
//         return (h2[r+1] + __int128(h2[l]) * (mod2 - p2[r + 1 - l])) % mod2;
//     };
//     pair<long long,long long> get(int l,int r){
//         return {get1(l,r),get2(l,r)};
//     }
// };
struct Hash {//下标从0开始
    const long long mod = 1e12+39;
    const int P = 13331;
    vector<long long> h, p;
    Hash(string s) : h(s.size() + 2), p(s.size() + 2) {//初始化构造函数，s表示参数,冒号后面表示需要初始化的成员变量
        int n = s.size();
        p[0] = 1;
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * P + s[i]) % mod;
            p[i + 1] = p[i] * P % mod;
        }
    };

    long long get(int l, int r) {
        return (h[r+1] + __int128(h[l]) * (mod - p[r + 1 - l])) % mod;
    };
};
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
	Hash hs(s);//初始化哈希表
  //hs.get(l,r);
  //正反哈希的时候注意的是正和逆的哈希值位置是对称的，需要对称的下标！！！！！！！
    for(int i=1;i<=m;i++){
        int l1,r1,l2,r2;
        if(hs.get(l1,r1)==hs.get(l2,r2)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}