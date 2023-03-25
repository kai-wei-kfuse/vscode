#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 2);
        vector<int> b(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        a[n + 1] = a[1];
        b[n + 1] = b[1];
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i + 1] >= b[i] - 1 || a[i] == b[i])
                flag++;
        }
        // if(ve1[1]<ve2[n]-1&&ve1[1]<ve2[n]-1){
        //     flag = 1;
        // }
        // cout << flag;
        if (flag < n) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
}