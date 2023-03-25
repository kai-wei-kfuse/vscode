#include <algorithm>
#include <iostream>
using namespace std;
int v[105], val[105], dp[105][105];
int main() {
    int n, V;
    cin >> n >> V;
    int num;
    for (int i = 1; i <= n; i++) {
        //cin >> num;
        for (int j = 1; j <= n; j++) {
            cin >> v[j] ;
        }
    
        for (int j = V; j >= 0; j--) {
            for (int k = 1; k <= n; k++)
                if (j >= k){
                    if(dp[j]< dp[j - k] + v[k]){
                        
                    }
                }
        }
    }
    cout << dp[V];
}