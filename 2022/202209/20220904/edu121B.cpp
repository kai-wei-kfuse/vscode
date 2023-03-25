#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        int len = s.length();
        int idx=-1;
        for (int i = len - 1; i >= 1;i--){
            if(s[i]-'0'+s[i-1]-'0'>=10){
                idx = i - 1;
                break;
            }
        }
        if(idx==-1){
            cout << s[0] - '0' + s[1] - '0';
            for (int i = 2; i < len;i++){
                cout << s[i];
            }
        }else{
            for (int i = 0; i < len;i++){
                if(i==idx){
                    cout << s[i] - '0' + s[i + 1] - '0';
                    i ++;
                }else
                cout << s[i] ;
            }
        }
        cout << '\n';
    }
}
