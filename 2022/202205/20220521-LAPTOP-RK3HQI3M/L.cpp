#include <iostream>
using namespace std;
long long a[100005], cnt;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += cnt;
        if (a[i] < a[i - 1]) {
            cnt += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << cnt;
}