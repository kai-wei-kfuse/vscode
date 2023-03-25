#include<iostream>
#include<map>
using namespace std;

map<string, int> mp1,mp2;

int main(){
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n;i++){
        cin >> s;
        mp1[s]++;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m;i++){
            cin >> s;
            if(mp1[s]&&mp2[s]==0){
                cout << "OK" << '\n';
                mp2[s]++;
            }
            else if(mp2[s]){
                cout << "REPEAT" << '\n';
            }
            else if(mp1[s]==0){
                cout << "WRONG" << '\n';
            }
    }
}