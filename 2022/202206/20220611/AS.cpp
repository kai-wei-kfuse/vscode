#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string a, b, c;
        cin >> a >> b;
        sort(a.begin(), a.end(), greater<char>());
        sort(b.begin(), b.end(), greater<char>());
        int ii = 0, jj = 0;
        while (!a.empty() && !b.empty()) {
            int tmp = a.back() < b.back();
            if (tmp && ii == k)
                tmp = 0;
            if (!tmp && jj == k)
                tmp = 1;
            if (tmp) {
                c.push_back(a.back());
                a.pop_back();
                ii++;
                jj = 0;
            } else {
                c.push_back(b.back());
                b.pop_back();
                jj++;
                ii = 0;
            }
        }
        cout << c << '\n';
    }
}