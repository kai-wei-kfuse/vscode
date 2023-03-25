#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int next_[N], txen_[N];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "?" + s;
    for (int i = 2, j = 0; i <= 2 * n; i++) {
        while (j && s[i] != s[j + 1])
            j = next_[j];
        if (s[i] == s[j + 1])
            j++;
        next_[i] = j;
    }
    for (int i = 1; i <= 2 * n; i++) {
        cout << next_[i] << ' ';
    }
    cout << endl;
    reverse(s.begin() + 1, s.end());
    cout << s << endl;
    for (int i = 2, j = 0; i <= 2 * n; i++) {
        while (j && s[i] != s[j + 1])
            j = txen_[j];
        if (s[i] == s[j + 1])
            j++;
        txen_[i] = j;
    }
    for (int i = 1; i <= 2 * n; i++) {
        cout << txen_[i] << ' ';
    }
    cout << endl;
    for (int i = 2; i <= 2 * n; i++) {
        if (i - 2 * next_[i] == 2 * n - i) {
            if (txen_[next_[i] + 1] == n - i) {
                for (int j = i; j > next_[i]; j--) {
                    cout << s[j];
                }
                cout << endl << i - 2 * next_[i] << endl;
                break;
            }
        }
    }
}