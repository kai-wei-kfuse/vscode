#include <bits/stdc++.h>
using namespace std;
char s[8];

int main() {
    cin >> s;
    int n;
    cin >> n;
    int len = strlen(s);
    sort(s, s + len);
    int cnt = 1;
    do {
        if (cnt == n) {
            cout << s;
        }
        cnt++;
    } while (next_permutation(s, s + len));
}