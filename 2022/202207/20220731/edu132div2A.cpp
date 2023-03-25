#include <iostream>
#include <map>
using namespace std;

int a[4];

int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= 3; i++) {
            cin >> a[i];
        }
        mp[n] = 1;
        mp[a[n]] = 1;
        mp[a[a[n]]] = 1;
        mp[a[a[a[n]]]] = 1;
        if (mp.size() == 4)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}