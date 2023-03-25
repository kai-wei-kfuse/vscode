#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string a;
    while (n--) {
        cin >> a;
        int ans = (a[0] - 'a') * 25;
        // cout << ans << endl;
        // cout << a[1] - 'a' << endl;
        if (a[0] > a[1])
            ans++;
        ans += a[1] - 'a';
        cout << ans << endl;
    }
}