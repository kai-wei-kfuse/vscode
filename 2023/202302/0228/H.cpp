#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s,a;
    cin >> s;
    getchar();
    getline(cin, a);
    int len = a.size();
    if(n>len){
        for (int i = 1; i <= n - len;i++){
            cout << s;
        }
        cout << a;
    }else{
        for (int i = len - n;i<len; i++) {
            cout << a[i];
        }
    }
}