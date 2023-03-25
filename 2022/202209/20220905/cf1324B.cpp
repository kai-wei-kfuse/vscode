#include <iostream>
using namespace std;

int a[50005], vis[50005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vis[i] = 0;
        }
        for (int i = 3; i <= n; i++) {
            vis[a[i - 2]]++;
            vis[a[i]]++;
            if (vis[a[i]] > 1)
                flag = 1;
            vis[a[i]]--;
        }
        if (flag) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}