#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1, 0), ve1(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        ve1[i] = ve[i] - ve[i - 1];
        if (ve1[i] > 0)
            sum += ve1[i];
    }
    cout << sum;
}