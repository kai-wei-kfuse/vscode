#include <bits\stdc++.h>
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
    int t;
    cin >> t;
    int ca = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > ve(n + 1);

        for (int i = 1; i <= n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            ve[i].first = mp[s1];
            if (s2[1] >= '0' && s2[1] <= '9') {
                ve[i].second = (s2[0] - '0') * 10 + s2[1] - '0';
            } else {
                ve[i].second = s2[0] - '0';
            }
            /*              cout << ve[i].first << ' ' << ve[i].second << '\n';
             */
        }
        string s1, s2;
        int m, d;
        cin >> s1 >> s2;
        m = mp[s1];
        if (s2[1] >= '0' && s2[1] <= '9') {
            d = (s2[0] - '0') * 10 + s2[1] - '0';
        } else {
            d = s2[0] - '0';
        }
        cout << m << ' ' << d << '\n';
        sort(ve.begin() + 1, ve.begin() + n + 1, cmp);
        for (int i = 1; i <= n; ++i) {
            cout << ve[i].first << " " << ve[i].second << endl;
        }
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            cout << ve[i].first << ' ' << ve[i].second << endl;
            if ((ve[i].first == m && ve[i].second > d) || ve[i].first > m) {
                flag = i;
                break;
            }
        }
        if (flag) {
            cout << "Case #" << ca << ": " << mp1[ve[flag].first] << ' ';
            if (ve[flag].second == 1) {
                cout << "1st";
            } else if (ve[flag].second == 2) {
                cout << "2nd";
            } else if (ve[flag].second == 3) {
                cout << "3rd";
            } else {
                cout << ve[flag].second << "th";
            }
            cout << '\n';
        } else {
            cout << "Case #" << ca << ": ";
            cout << "See you next year" << '\n';
        }
        ca++;
    }
}
/*
9
Aug 1st
Mar 1st
Apr 1st
Nov 1st
Oct 1st
May 1st
Jul 1st
Sept 1st
May 1st
May 6th
*/