#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<char> > s(9, vector<char>(9));
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                cin >> s[i][j];
            }
        }
        int ans=-1;
        int numr = 0, numb = 0;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (s[i][j] == 'R') {
                    numr++;
                }
                
            }
            if (numr == 8) {
                ans = 0;
            }
            numr = 0;
        }
        numr = 0, numb = 0;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (s[j][i] == 'B') {
                    numb++;
                }
            }
            if (numb == 8) {
                ans = 1;
            }
            numr = 0, numb = 0;
        }
        if (ans == 1) {
            cout << "B" <<endl;
        } else if (ans == 0) {
            cout << "R" <<endl;
        }
    }
}