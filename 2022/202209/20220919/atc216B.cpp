#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<pair<string, string>, int> mp;
    int flag = 0;
    for (int i = 1; i <= n;i++){
        string s1, s2;
        cin >> s1>> s2;
        if(mp[{s1,s2}]==0)
        mp[{s1, s2}] = 1;
        else{
            flag = 1;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}