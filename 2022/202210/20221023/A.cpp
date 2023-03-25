#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int q = 0, a = 0, flag = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'A')
                a++;
            if (s[i] == 'Q')
                q++;
            if (q > a)
                flag = 1;
        }
        if(flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}