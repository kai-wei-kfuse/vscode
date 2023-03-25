#include <bits/stdc++.h>
using namespace std;
struct edge {
    int num;
    char s;
};
bool is_six(int x) {
    while (x) {
        x = x / 16;
        if (x == 0)
            return false;
        else if (x == 1)
            return true;
    }
}
char alpha[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
string to_leo(int x) {
    string s;
    while (x) {
        int y = x % 16;
        s = alpha[y] + s;
        x = x / 16;
    }
    return s;
}
signed main() {
    string s;
    while (cin >> s) {
        vector<edge> ve;
        char x;
        x = s[0];
        int cnt = 1;
        int flag = 0;
        for (int i = 1; i < s.size(); i++) {
            if (x == s[i]) {
                cnt++;
            } else {
                ve.push_back({cnt, x});
                x = s[i];
                cnt = 1;
            }
        }
        ve.push_back({cnt, x});
        int state = 0;
        int pos = 0;
        for (int i = 0; i < ve.size(); i++) {
            if (ve[i].num == 1) {
                if (i + 1 < ve.size() &&
                    ve[i].s > ve[i + 1].s)  //若可以减小放在前面 否则放最后
                {
                    state = 1;
                    pos = i;
                    break;
                }
                state = 1;
                pos = i;
            }
        }
        if (state != 1) {
            for (int i = ve.size() - 1; i >= 0; i--)  //变成 F我们放在最后
            {
                if (is_six(ve[i].num)) {
                    ve[i].num--;
                    state = 2;
                    break;
                }
            }
        }

        if (state == 1) {
            for (int i = 0; i < ve.size(); i++) {
                if (i != pos)
                    cout << ve[i].s << to_leo(ve[i].num);
                else
                    continue;
            }
        } else if (state == 2) {
            for (int i = 0; i < ve.size(); i++) {
                cout << ve[i].s << to_leo(ve[i].num);
            }
        } else {
            ve[0].num--;
            for (int i = 0; i < ve.size(); i++) {
                cout << ve[i].s << to_leo(ve[i].num);
            }
        }
        cout << endl;
    }
}
