#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> ve(21, 0);
    int tmp = 1;
    for (int i = 1; i <= 20; i++) {
        if (i % 5 == 0) {
            tmp += 2;
        }
        ve[i] = tmp;
    }
    for (auto i : ve) {
        cout << i << ' ';
    }
    cout << endl;
    int x = upper_bound(ve.begin() + 1, ve.end(), 3) - ve.begin();
    cout << x;
}