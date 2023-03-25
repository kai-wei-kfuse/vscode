#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
vector<long long> xx(6);
vector<int> ve(1e5+5);
int main(){
    IOS;
    int t;
    cin>>t;
    int cnt = 1;
    while(t--){
        
        for (int i = 1; i <= 5;i++){
            cin >> xx[i];
        }
        int n;
        cin >> n;
        
        long long ans = 0;
        for (int i = 1; i <= n;i++){
            cin >> ve[i];
            if(ve[i]>=1&&ve[i]<=48){
                ans += xx[1];
            }
            else if(ve[i]>48&&ve[i]<=56){
                ans += xx[2];
            }
            else if(ve[i]>56&&ve[i]<=60){
                ans += xx[3];
            }
            else if(ve[i]>60&&ve[i]<=62){
                ans += xx[4];
            }
            else if(ve[i]==63){
                ans += xx[5];
            }
        }
        cout << "Case #" << cnt++ << ": " << ans * 10000 << endl;
    }
}