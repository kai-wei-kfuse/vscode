#include <iostream>
using namespace std;
int a[100005], q[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int len = 0;
    q[0] = -0x3f3f3f;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = r + l + 1 >> 1;
            if (q[mid] < a[i])
                l = mid;
            else {
                r = mid - 1;
            }
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len;
}