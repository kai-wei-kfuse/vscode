#include <iostream>
#include <map>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
map<int, int> mp;
int main() {
    int n;
    IOS;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            mp[s[i]]++;
        }
        int tmp = mp.size();
        string x = s.substr(0, tmp);
        // cout << x << endl;
        int flag = 0;
        for (int i = 0; i < len;) {
            for (int j = 0; j < tmp; j++, i++) {
                if (i == len)
                    break;
                if (s[i] != x[j])
                    flag = 1;
            }
        }
        mp.clear();
        if (flag == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}