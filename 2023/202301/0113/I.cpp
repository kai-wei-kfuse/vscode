#include <bits/stdc++.h>
using namespace std;

int next_[100];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> str(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> str[i];
        }
        int j = 0;
        str[1] = " " + str[1];
        for (int i = 2; i <= 60; i++) {
            while (j && str[1][i] != str[1][j + 1])
                j = next_[j];
            if (str[1][i] == str[1][j + 1])
                j++;
            next_[i] = j;
        }
        int ans = 0, res = 0;
        for (int l = 1; l <= 60; l++) {
            for (int len = 1; len + l <= 60; len++) {
                for (int _ = 2; _ <= n; _++) {
                    str[_] = "?" + str[_];
                    int j = 0;
                    for (int i = 2; i <= l; i++) {
                        while (j && str[_][i] != str[1][j + 1])
                            j = next_[j];
                        if (str[_][i] == str[1][j + 1])
                            j++;
                        if (j == len) {
                            ans++;
                            j = next_[j];
                        }
                    }
                }
            }
        }
    }
}