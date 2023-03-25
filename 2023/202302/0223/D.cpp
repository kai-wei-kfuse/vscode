#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    map<int, int> mp;
    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;
        if (x <= 1) {
            int tmp;
            cin >> tmp;
        }else if(x>1){
        for (int i = 1; i <= x; i++) {
            int tmp;
            cin >> tmp;
            mp[tmp]=1;
        }
        }
    }
    int n;
    cin >> n;
    int flag = 0;
    vector<int> ve;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (mp[tmp] == 0) {
            ve.push_back(tmp);
            mp[tmp] = -1;
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "No one is handsome";
    } else {
        int si = ve.size();
        for (int i = 0; i < si; i++) {
            cout << ve[i];
            if(i!=si-1){
                cout << " ";
            }
        }
    }
}