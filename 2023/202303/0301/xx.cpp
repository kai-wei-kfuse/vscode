#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> q(100005);
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (q[len] < ve[i]) {
            q[++len] = ve[i];
        } else {
            int pos = lower_bound(q.begin() + 1, q.begin() + len + 1, ve[i]) - q.begin();
            len = max(len, pos);
            q[pos] = ve[i];
        }
    }
    cout << len;
}