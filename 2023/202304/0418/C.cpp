#include <bits/stdc++.h>
using namespace std;

#define eps 1e-10
#define pi 3.1415926535

int main()
{
    int n;
    double R, xi;
    cin >> n >> R >> xi;
    if (xi > pi)
        xi = 2 * pi - xi;
    double tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
    }
    if (xi + eps < 2)
    {
        printf("%.7f\n", xi * R);
    }
    else
    {
        printf("%.7f\n", R * 2);
    }
}