#include<iostream>
#include<map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int len = s.length();
        map<char, int> mp;
        int ans = 0;
        for (int i = 0; i <= len;i++){
            if(mp[s[i]]==0){
                mp[s[i] ]= 1;
            }
            else{
                mp.clear();
                ans+=2;
            }
        }
        cout << len-ans << '\n';
    }
}