#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            mp[tmp]++;
            if(mp[tmp]>1)
                flag = 1;
        }
        if(flag){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}