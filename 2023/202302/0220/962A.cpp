#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;
    vector<int> a(n + 2);
    int sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    int res = 0;
    for (int i = 1; i <= n;i++){
        res += a[i];
        if(sum%2==0&&res>=sum/2){
            cout << i;
            return 0;
        }
        if(sum%2&&res>=sum/2+1){
             cout << i;
            return 0;
        }
    }
}