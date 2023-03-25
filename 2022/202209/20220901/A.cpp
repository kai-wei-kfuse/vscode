#include<iostream>
#include<algorithm>
using namespace std;
int v[] = {3, 3, 3, 1, 5, 1};
int main(){
    long long ans = 0;
    // for (int i = 1; i <= 20;i++){
    //     for (int j = 1; j <= i;j++){
    //         if(__gcd(i,j)*3>=i*j/__gcd(i,j)){
    //             if(i==j)
    //                 ans++;
    //                 else
    //                     ans += 2;
    //         }
            
    //     }
    //     cout << ans << endl;
    // }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n--;
        ans = 1;
        ans += n / 6 * 16;
        for (int i = 0; i < n % 6;i++){
            ans += v[i];
        }
        cout << ans << '\n';
    }
}