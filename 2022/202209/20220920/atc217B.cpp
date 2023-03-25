#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
string s[] = {"ABC", "ARC", "AGC", "AHC"};
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    mp["ABC"] = 0;
    mp["ARC"] = 0;
    mp["AGC"] = 0;
    mp["AHC"] = 0;
    mp[s1]++;
    mp[s2]++;
    mp[s3]++;
    for (int i = 0; i <= 3; i++) {
        if (mp[s[i]] == 0) {
            cout << s[i];
        }
    }
}