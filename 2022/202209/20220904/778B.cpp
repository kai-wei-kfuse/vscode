#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        map<char, int> mp;
        for(auto i:s){
            mp[i] ++;
        }
        int idx=0;
        for(auto i:s){
            if(mp[i]>1){
                idx++;
                mp[i]--;
            }else{
                break;
            }
        }
        int len = s.length();
        for (int i = idx; i <len ;i++){
            cout << s[i];
        }
        cout << '\n';
    }
}