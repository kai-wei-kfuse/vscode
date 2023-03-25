#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
map<int, string> mp1;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}
int main() {
    mp["Jan"] = 1;
    mp["Feb"] = 2;
    mp["Mar"] = 3;
    mp["Apr"] = 4;
    mp["May"] = 5;
    mp["Jun"] = 6;
    mp["Jul"] = 7;
    mp["Aug"] = 8;
    mp["Sept"] = 9;
    mp["Oct"] = 10;
    mp["Nov"] = 11;
    mp["Dec"] = 12;
    mp1[1] = "Jan";
    mp1[2] = "Feb";
    mp1[3] = "Mar";
    mp1[4] = "Apr";
    mp1[5] = "May";
    mp1[6] = "Jun";
    mp1[7] = "Jul";
    mp1[8] = "Aug";
    mp1[9] = "Sept";
    mp1[10] = "Oct";
    mp1[11] = "Nov";
    mp1[12] = "Dec";
    vector<pair<int, int>> ve;
    ve[0] = make_pair(1,1);
    int i = 0;
    while (i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == "S")
            break;
        ve[i].first = mp[s1];
        if (s2[1] >= '0' && s2[1] <= '9') {
            ve[i].second = (s2[0] - '0') * 10 + s2[1] - '0';
        } else {
            ve[i].second = s2[0] - '0';
        }
        cout << ve[i].first << ' ' << ve[i].second << '\n';
    }
    sort(ve.begin() + 1, ve.begin() + i, cmp);
    for (auto a : ve) {
        cout << a.first << " " << a.second << endl;
    }
}