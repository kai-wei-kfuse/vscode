#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
map<string, int> mp;
map<int, string> mp1;
typedef pair<int, int> P;

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

    int cnt = 0;
    while (t--) {
        int n;
        cnt++;
        cin >> n;
        vector<P> ve;
        string s1, s2;
        for (int i = 1; i <= n; i++) {
            cin >> s1 >> s2;
            int num = s2[0] - '0';
            if (isdigit(s2[1])) {
                num = num * 10 + s2[1] - '0';
            }
            ve.push_back({mp[s1], num});
        }
        sort(ve.begin(), ve.end());

        cin >> s1 >> s2;

        int mon = mp[s1];
        int num = s2[0] - '0';

        if (isdigit(s2[1])) {
            num = num * 10 + s2[1] - '0';
        }
        int fg = 0;
        for (int i = 0; i < ve.size(); i++) {
            if (ve[i].fi == mon) {
                if (ve[i].se > num) {
                    fg = i;
                    break;
                }
            } else if (ve[i].fi > mon) {
                fg = i;
                break;
            }
        }
        cout << "Case #" << cnt << ": ";
        if (fg) {
            cout << mp1[ve[fg].fi] << " ";
            if (ve[fg].se % 10 == 1 && ve[fg].se != 11)
                cout << ve[fg].se << "st";
            else if (ve[fg].se % 10 == 2 && ve[fg].se != 12)
                cout << ve[fg].se << "nd";
            else if (ve[fg].se % 10 == 3 && ve[fg].se != 13)
                cout << ve[fg].se << "rd";
            else {
                cout << ve[fg].se << "th";
            }
        } else {
            cout << "See you next year";
        }

        cout << endl;
    }
}