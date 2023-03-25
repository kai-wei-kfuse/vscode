#include <cstring>
#include <iostream>
using namespace std;
string a, b;
void solve(string a, string b) {
    if (a.empty())
        return;
    int k = a.find(b[0]);
    char tmp = b[0];
    b.erase(b.begin());
    string ax = a.substr(0, k);
    string bx = b.substr(0, k);
    string axx = a.substr(k + 1);
    string bxx = b.substr(k);
    // cout << ax << ' ' << bx << endl;
    // cout << axx << ' ' << bxx << endl;
    solve(ax, bx);
    solve(axx, bxx);
    cout << tmp;
}
int main() {
    cin >> a >> b;
    int len = a.length();
    solve(a, b);
}