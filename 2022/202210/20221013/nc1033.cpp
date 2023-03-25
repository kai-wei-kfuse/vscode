#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    map<string, pair<string, int> > mp;
    mp["aow"] = {"xuebao", 0};
    mp["wuo"] = {"sheli", 0};
    mp["wri"] = {"tuboshu", 0};
    mp["aoa"] = {"huli", 0};
    mp["yia"] = {"zhangzi", 0};
    mp["mie"] = {"yanyang", 0};
    int len = s.length();
    string tmp = "", res;
    vector<string> chack;
    int cnt = 0, t = 0;
    for (int i = 0; i < len; i++) {
        if (t != 3) {
            tmp += s[i];
            t++;
            // cout << tmp << endl;
            // cout << t << endl;
        }
        if (t == 3) {
            if (mp.count(tmp)) {
                cnt++;
                // cout << cnt << endl;
                if (mp[tmp].second == 0) {
                    res = tmp;
                    chack.push_back(tmp);
                    mp[tmp].second = 1;
                }
            } else {
                chack.push_back(tmp);
            }
            tmp = "";
            t = 0;
        }
    }

    // cout << cnt << endl;
    if (chack.size() > 1 || t != 0) {
        cout << "15";
    } else if (cnt <= 3) {
        cout << "zhishi" << mp[res].first;
    } else if (cnt > 3) {
        cout << mp[res].first << "bizui";
    }
}