#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, m;
    cin >> n >> k >> m;
    vector<double> ve;
    for (int i = 1; i <= n;i++){
        double sum = 0;
        double minn = 0x3f3f3f3f, maxn = 0;
        for (int j = 1; j <= k;j++){
            
            double tmp;
            cin >> tmp;
            sum += tmp;
            minn = min(minn, tmp);
            maxn = max(maxn, tmp);
            ve.push_back((sum-maxn-minn) / (double)(k - 2));
        }
    }
    sort(ve.begin(), ve.end(),greater<double>());
    for (int i = m-1; i >=0 ;i--){
        printf("%.3f ", ve[i]);
    }
}