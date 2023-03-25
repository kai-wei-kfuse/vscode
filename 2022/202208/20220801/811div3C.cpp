#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int flag = 0;
vector<int> ss;

void dfs(int n, vector<int> s, int last) {
    if (n == 0) {
        long long sum = 0;
        for (auto i : s) {
            // cout << i;
            sum = sum * 10 + i;
            // cout << sum << endl;
        }
        ss.push_back(sum);
        // cout << '\n';
        return;
    }
    for (int i = last + 1; i <= 9; i++) {
        if (n - i >= 0) {
            // cout << i;
            s.push_back(i);
            dfs(n - i, s, i);
            s.pop_back();
        } else {
            break;
        }
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> s;
        dfs(n, s, 0);
        sort(ss.begin(), ss.end());
        cout << ss[0] << '\n';
        ss.clear();
    }
}