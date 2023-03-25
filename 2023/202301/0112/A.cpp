#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    s = "?" + s;
    string ans1 = "", ans2 = "";
    vector<int> vis1(len + 1, 0), vis2(len + 1, 0);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (s[i] - '0' + s[j] - '0' == 0 && vis1[i] == 0 && vis2[j] == 0) {
                ans1 += s[i];
                ans2 += s[j];
                vis1[i] = 1, vis2[j] = 1;
            }
        }
    }
    vector<int> vis1_, vis2_;
    string ans1_ = "", ans2_ = "", res1 = "", res2 = "";

    int maxn = -1, res = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            // if (vis1[i] == 0 && vis2[j] == 0)
            // cout << s[i] << ' ' << s[j] << endl;
            if (s[i] - '0' + s[j] - '0' == 10 && vis1[i] == 0 && vis2[j] == 0) {
                ans1 += s[i];
                ans2 += s[j];
                vis1[i] = 1, vis2[j] = 1;
                vis1_ = vis1;
                vis2_ = vis2;
                for (int i = 1; i <= len; i++) {
                    for (int j = 1; j <= len; j++) {
                        // if (vis1[i] == 0 && vis2[j] == 0)
                        //  cout << s[i] << ' ' << s[j] << endl;
                        if (s[i] - '0' + s[j] - '0' == 9 && vis1_[i] == 0 &&
                            vis2_[j] == 0) {
                            ans1_ += s[i];
                            ans2_ += s[j];
                            vis1_[i] = 1, vis2_[j] = 1;
                            res++;
                        }
                    }
                }
                // cout << ans1 << ' ' << ans2 << endl;
                if (res > maxn) {
                    for (int i = 1; i <= len; i++) {
                        for (int j = 1; j <= len; j++) {
                            if (vis1_[i] == 0 && vis2_[j] == 0) {
                                ans1_ += s[i];
                                ans2_ += s[j];
                                vis1_[i] = 1, vis2_[j] = 1;
                            }
                        }
                    }
                    res1 = ans1_;
                    res2 = ans2_;
                }
            }
        }
    }
    string xx = "", yy = "";
    for (auto i : ans1) {
        xx += i;
    }
    for (auto i : res1) {
        xx += i;
    }
    for (auto i : ans1) {
        xx += i;
    }
    for (auto i : res1) {
        xx += i;
    }
}