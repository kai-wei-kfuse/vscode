#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int next_[400005];

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        s = "?" + s;
        int j = 0;
        for (int i = 2; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = next_[j];
            if (s[i] == s[j + 1])
                j++;
            next_[i] = j;
        }
        int x = n;
        vector<int> ve;
        while (x) {
            x = next_[x];
            if (x != 0)
                ve.push_back(x);
        }
        sort(ve.begin(), ve.end());
        int len = ve.size();
        for (int i = 0; i < len; i++) {
            cout << ve[i] << ' ';
        }
        cout << n << endl;
    }
}