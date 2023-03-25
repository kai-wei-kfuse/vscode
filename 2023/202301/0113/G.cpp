#include <bits/stdc++.h>
using namespace std;

int next_[1000006];

int main() {
    string s;
    while (cin >> s, s != ".") {
        int n = s.size();
        s = "x" + s;
        int j = 0;
        for (int i = 2; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = next_[j];
            if (s[i] == s[j + 1])
                j++;
            next_[i] = j;
        }
        if (n % (n - next_[n]) == 0) {
            cout << n / (n - next_[n]) << endl;
        } else {
            cout << "1" << endl;
        }
    }
}