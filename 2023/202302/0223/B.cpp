#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int h = 0,m=0;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    cout << h << ' ' << m<<endl;
    if((h>=0&&h<12)||h==12&&m==0){
        cout << "Only " << s << ".  Too early to Dang.";
    }
    else {
        for (int i = 1; i <= h - 12;i++){
            cout << "Dang";
        }
        if(m!=0){
            cout << "Dang";
        }
    }
}