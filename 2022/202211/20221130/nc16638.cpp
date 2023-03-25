#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,a;
    cin >> a;
    int len = a.size();
    for (int i = 0; i < len;i++){
        s += a[i];
        if(i>=2 && a[i]=='b'&&a[i-1]=='j'&&a[i-2]=='c'){
            s += ',';
        }
    } 
    cout << s;
}