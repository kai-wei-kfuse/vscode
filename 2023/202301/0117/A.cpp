#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    string a;
    cin >> a;
    int n = s.size();
    int len = a.size();
    map<char, int> mp,yuan;
    int flag = 0;
    for (int i = 0; i < len  ;i++){
        yuan[a[i]]++;
    }
    int ans = 0;
    for (int i = 0,l=0; i < n; i++) {
        //cout << s[i] << ' ';
        if(yuan[s[i]]==0&&s[i]!='?'){
            i ++;
            //cout << s[i] << ' ';
            mp.clear();
            l = i;
            if (i > n) break;
            
        }
        mp[s[i]]++;
        if (i >= len+l) {
            mp[s[l]]--;
            if (mp[s[l]]<=yuan[s[l]] && flag == 1) {
                flag = 0;
            }
            l++;
        }
        if (mp[s[i]] > yuan[s[i]] && s[i] != '?') {
            flag =1;
        }
        //cout <<  ' '<<flag<<endl;
        if (flag == 0&&i-l>=len-1) ans++;
    }
    cout << ans;
}