#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = s;
    vector<int> ans;
    int flag = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'B') {
            if (s[i + 1] == 'B') {
                s[i + 1] = 'W';
            } else {
                s[i + 1] = 'B';
            }
            ans.push_back(i);
        }
    }
    if (s[n - 1] != 'W') {
        ans.clear();
        for (int i = 0; i < n; i++) {
            if (ss[i] == 'W') {
                if (ss[i + 1] == 'B') {
                    ss[i + 1] = 'W';
                } else {
                    ss[i + 1] = 'B';
                }
                ans.push_back(i);
            }
        }
        if(ss[n-1]!='B'){
            flag = 0;
        }
    }
    if(flag){
        cout << ans.size() << endl;
        for(auto i:ans){
            cout << i+1 << ' ';
        }
    }else{
        cout << "-1";
    }
}