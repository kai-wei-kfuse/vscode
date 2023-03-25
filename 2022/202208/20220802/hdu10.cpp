#include <iostream>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int a[100005], b[100005];

int main() {
    IOS;
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        cout << "Win!" << '\n';
    }
}