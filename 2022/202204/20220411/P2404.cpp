#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> a;
void dfs(int x, int sum) {
    if (sum == n) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i];
            if (i != a.size() - 1)
                cout << "+";
        }
        cout << endl;
        // cout << 'd' << endl;
        return;
    }
    for (int i = x; i < n; i++) {
        if (sum + i <= n) {
            a.push_back(i);
            dfs(i, sum + i);
            a.pop_back();
        }
    }
}
int main() {
    cin >> n;
    dfs(1, 0);
}
