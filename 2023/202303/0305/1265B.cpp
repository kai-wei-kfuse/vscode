#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ve(n + 1,0);
        for (int i = 1; i <= n;i++){
            int tmp;
            cin >> tmp;
            ve[tmp] = i;
        }
        int maxn = 0, minn = 0x3f3f3f3f;
        string s = "";
        for (int i = 1; i <= n;i++){
            maxn = max(maxn, ve[i]);
            minn = min(minn, ve[i]);
            if(maxn-minn+1==i){
                s += '1';
            }else{
                s += '0';
            }
        }
        cout << s << endl;
    }
}