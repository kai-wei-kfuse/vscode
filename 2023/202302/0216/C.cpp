#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n;i++){
            cin >> ve[i];
        }
        int ans=0;
        int flag = -1;
        for (int i = 2; i <= n;i++){
            if(ve[i]<ve[i-1]){
                flag = i-1;
            }
            if(flag!=-1&&ve[i]>ve[i-1]){
                ans = flag;
                flag = -1;
            }
        }
        cout << ans<< endl;
    }
}