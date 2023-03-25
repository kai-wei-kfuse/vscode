#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int get(vector<int> ve, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i--) {
        res = res * 10 + ve[i];
    }
    // cout << res;
    return res;
}

int count(int n, int x) {
    if (!n)
        return 0;
    vector<int> ve;
    while (n) {
        ve.push_back(n % 10);
        n /= 10;
    }
    int res = 0;
    n = ve.size();
    for (int i = n - 1 - !x; i >= 0; i--) {
        if (i < n - 1) {
            res += get(ve, n - 1, i + 1) * (int)pow(10, i);
            if (!x)
                res -= pow(10, i);
        }
        if (ve[i] == x)
            res += get(ve, i - 1, 0) + 1;
        else if (ve[i] > x)
            res += pow(10, i);
    }
    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b, a || b) {
        if (a > b)
            swap(a, b);
        for (int i = 0; i < 10; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << '\n';
    }
}