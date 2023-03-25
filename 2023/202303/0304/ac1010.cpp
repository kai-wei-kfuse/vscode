#include <bits/stdc++.h>
using namespace std;
vector<int> ve(1005);
vector<int> q1(1005, 0), q2(1005, 0);
int main() {
    int x;
    int len1 = 0, len2 = 0;
    while (cin >> x) {
        int pos = lower_bound(q1.begin(), q1.begin() + len1, x) - q1.begin();
        if (pos == len1)
            q1[len1++] = x;
        else
            q1[pos] = x;

        int pos2 = upper_bound(q2.begin(), q2.begin() + len2, x, greater<int>()) - q2.begin();
        if (pos2 == len2)
            q2[len2++] = x;
        else
            q2[pos2] = x;
    }
    cout << len2 << endl
         << len1;
}