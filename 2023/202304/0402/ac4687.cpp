#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int next_[205];
string a[4005];

void get_next(string a) {
    a = "?" + a;
    int lena = a.size();
    for (int i = 2, j = 0; i <= lena; i++) {
        while (j && a[j + 1] != a[i])
            j = next_[j];
        if (a[j + 1] == a[i]) j++;
        next_[i] = j;
    }
}

inline int kmp(string a, string b) {
    b = "?" + b;
    a = "?" + a;
    int lena = a.size() - 1;
    int lenb = b.size() - 1;
    for (int i = 1, j = 0; i <= lenb; i++) {
        while (j && a[j + 1] != b[i])
            j = next_[j];
        if (a[j + 1] == b[i]) j++;
        if (j == lena) return 1;
    }
    return 0;
}

int main() {
    IOS int n;
    while (cin >> n, n) {
        string s;
        cin >> s;
        int len = s.size();
        int mxlen = 0;
        string mxstr = "";
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }
        int k;
        for (k = len; k >= 1; k--) {
            for (int j = 0; j + k <= len; j++) {
                int flag = 1;
                string tmp = s.substr(j, k);
                get_next(tmp);
                for (int i = 1; i < n; i++) {
                    //   cout << s.substr(j, k) << " " << a[i] << endl;
                    if (!kmp(tmp, a[i])) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    if (k > mxlen) {
                        mxlen = k;
                        mxstr = tmp;
                    } else if (k == mxlen) {
                        mxstr = min(mxstr, tmp);
                    }
                }
            }
            if (mxlen == k) break;
        }
        if (mxlen == 0) {
            cout << "IDENTITY LOST" << '\n';
        } else {
            cout << mxstr << '\n';
        }
    }
}