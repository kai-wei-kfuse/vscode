#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    int flag = 1;
    int a=0, b=0, c=0;
        for (int i = 0; i < len; i++) {
            if(s[i]=='a'){
                a++;
                if(c!=0||b!=0){
                    flag = 0;
                }
            }if(s[i]=='b'){
                b++;
                if(a==0){
                    flag = 0;
                }
                if(c!=0){
                    flag = 0;
                }
            }if(s[i]=='c'){
                c++;
                if(b==0||a==0){
                    flag = 0;
                }
            }
        }
    if(a!=c&&b!=c){
        flag = 0;
    }
    if(a==0||b==0||c==0){
        flag = 0;
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}