#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1), q1(n + 1), q2(n + 1);
    vector<int> ans1(n + 1), ans2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        q1[i] = 0;
        q2[i] = 0;
    }
    q1[0] = 0;
    q2[0] = 0;
    int len = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = r + l + 1 >> 1;
            if (q1[mid] < ve[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        
        len = max(len, r + 1);
        ans1[i] = len;
        q1[r + 1] = ve[i];
       // cout << ans1[i] << ' ';
    }
    len=0;
    //cout << endl;
    for (int i = n; i>=1; i--) {
        int l = 0, r = len;
        while (l < r) {
            int mid = r + l + 1 >> 1;
            if (q2[mid] < ve[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        len = max(len, r + 1);
        q2[r + 1] = ve[i];
        ans2[i] = len;
        //cout << ans2[i] << ' ';
    }
    //cout << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ans1[i] + ans2[i] - 1);
    }
    cout <<n- ans << endl;
}
