#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int len = 0;
    int i = 0;
    int ans = 0;
    while (i < n) {
        if (s[i] == '*') {
            i++;
            continue;
            len = 0;
        }
        if (s[i] == '.') len++;
        if (i + 1 >= n || s[i + 1] == '*') {
            if (len != 0) {
                if(len==1){
                    ans++;
                    if(a>b&&a>0){
                        a--;
                    }else if(b>0){
                        b--;
                    }
                }
                else if (len % 2) {
                    if (a > b) {
                        ans += min(a, len / 2 + 1);
                        a -= min(a, len / 2 + 1);
                        ans += min(b, len / 2);
                        b -= min(b, len / 2);
                    } else {
                        ans += min(b, len / 2 + 1);
                        b -= min(b, len / 2 + 1);
                        ans += min(a, len / 2);
                        a -= min(a, len / 2);
                    }
                } else {
                    ans += min(b, len / 2);
                    b -= min(b, len / 2);
                    ans += min(a, len / 2);
                    a -= min(a, len / 2);
                }
            }
            //cout << len<<endl;
            len = 0;
        }
        i++;
        if (a == 0 && b == 0) break;
    }
    cout << ans;
}