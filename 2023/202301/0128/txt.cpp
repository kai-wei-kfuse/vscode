#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;

int next_[1000005];

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        string a = "?" + s1 + s2;
        int j = 0;
        int n = a.size() - 1;
        for (int i = 2; i <= n; i++) {
            while (j && a[i] != a[j + 1])
                j = next_[j];
            if (a[i] == a[j + 1])
                j++;
            next_[i] = j;
        }
        if (next_[n]) {
            int res = min(next_[n], (int)s1.size());
            for (int i = 1; i <= res; i++) {
                cout << a[i];
            }
            cout << " " << next_[n];
        } else {
            cout << 0;
        }
        cout << endl;
    }
}