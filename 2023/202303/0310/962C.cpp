#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < (1 << len); i++) {
        vector<int> t;
        int tmp = i;
        int cnt = 0;
        int num = 0;
        for (int j = 0; j < len; j++) {
            if ((1 << j) & i) {
                num *= 10;
                num += s[j] - '0';
                t.push_back(s[j] - '0');
            }
        }
       // cout << num << endl;
        if (t.size() && t[0] != 0 && (int)sqrt(num) * (int)sqrt(num) == num) {
            ans = min(ans, len-(int)t.size());
        }
    }
    if(ans==0x3f3f3f3f){
        cout << "-1" << endl;
    }else
    cout << ans << endl;
}