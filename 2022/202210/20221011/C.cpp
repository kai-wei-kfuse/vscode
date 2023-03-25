#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c;
    double h, m, s;
    cin >> h >> m >> s;

    cin >> a >> b >> c;
    double ans1 = 0;

    ans1 = 360.0 / h * a;

    ans1 += b / m * (360.0 / h);

    ans1 += (c / (s * m)) * (360.0 / h);

    cout <<fixed<<setprecision(2)<< ans1;

    cout << ' ' <<fixed<<setprecision(2)<< (360.0 / m * b + (360.0 / m) * (c / s));
    
    cout << ' ' <<fixed<<setprecision(2)<< (360.0 / s * c);
}