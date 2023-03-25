#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    string a = "abcdefghijklmnopqrstuvwxyz";
    int x = 0;
    for (int i = 0; i < len; i++) {
        if(s[i]<=a[x]){
            s[i] = a[x];
            x++;
        }
    }
    if(x==26){
        cout << s;
    }else{
        cout << "-1";
    }
}