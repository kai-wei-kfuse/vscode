#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    map<char, int> mp;
    map<char, int> mp2;
    int cnt = 1;
    for (int i = 0; i < len; i++) {
        if (mp[s[i]] == 0) {
            mp[s[i]] = 1;
        }
    }
    cout << "int[] arr = new int[]{";
    vector<int> s1;
    for (auto i : mp) {
        s1.push_back(i.first);
    }
    sort(s1.begin(), s1.end(), greater<int>());
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i]-'0';
        if (i != s1.size() - 1) {
            cout << ",";
        }
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (int i = 0; i < s1.size();i++){
        mp2[s1[i]] = i;
    }
        for (int i = 0; i < len; i++) {
            cout << mp2[s[i]];
            if (i != len - 1) {
                cout << ",";
            }
        }
    cout << "};";
}