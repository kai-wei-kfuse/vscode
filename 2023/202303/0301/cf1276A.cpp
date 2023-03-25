#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int len = s.size();
        vector<int> ans;
        for (int i = 2; i < len;) {
            // cout << i << endl;
            if (s[i] == 'o' && s[i - 1] == 'w' && s[i - 2] == 't') {
                if(s[i+2] == 'e' && s[i+1] == 'n'){
                    ans.push_back(i);
                    i += 5;
                }
                else{
                    ans.push_back(i - 1);
                    i += 3;
                }
            } else if (s[i] == 'e' && s[i - 1] == 'n' && s[i - 2] == 'o') {
                ans.push_back(i - 1);
                i += 3;
            } else {
                i++;
            }
        }
        cout << ans.size() << endl;
        if (ans.size()) {
            for (auto i : ans) {
                cout << i + 1 << ' ';
            }
        }
        cout << endl;
    }
}