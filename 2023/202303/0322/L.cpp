#include <bits/stdc++.h>
using namespace std;

vector<int> at1(10), at2(10), h1(10), h2(10);
vector<int> nu1(10), nu2(10);

int n, m;
double ans1, ans2, ans3;

void dfs(int x, double p, int num1, int num2) {
    // cout << x << ' ' << num1 << ' ' << num2 << " " << p << endl;
    if (num1 == 0 && num2 == 0) {
        ans3 += p;
    } else if (num1 == 0) {
        ans2 += p;
    } else if (num2 == 0) {
        ans1 += p;
    } else {
        if (x == 0) {
            int tmp = 0;
            for (int i = 1; i <= n; i++) {
                if (h1[i] > 0 && (tmp == 0 || nu1[i] < nu1[tmp])) {
                    tmp = i;
                }
            }
            nu1[tmp]++;
            double ps = 0;
            for (int j = 1; j <= m; j++) {
                if (h2[j] <= 0) continue;
                h2[j] -= at1[tmp];
                h1[tmp] -= at2[j];
                ps = 1.0 / num2;
                if (h2[j] <= 0) num2--;
                if (h1[tmp] <= 0) num1--;
                dfs(1, p * ps, num1, num2);
                if (h2[j] <= 0) num2++;
                if (h1[tmp] <= 0) num1++;
                h2[j] += at1[tmp];
                h1[tmp] += at2[j];
            }
            nu1[tmp]--;
        } else {
            int tmp = 0;
            for (int i = 1; i <= m; i++) {
                if (h2[i] > 0 && (tmp == 0 || nu2[i] < nu2[tmp])) {
                    tmp = i;
                }
            }
            nu2[tmp]++;
            double ps = 0;
            for (int j = 1; j <= n; j++) {
                if (h1[j] <= 0) continue;
                h1[j] -= at2[tmp];
                h2[tmp] -= at1[j];
                ps = 1.0 / num1;
                if (h1[j] <= 0) num1--;
                if (h2[tmp] <= 0) num2--;
                dfs(0, p * ps, num1, num2);
                if (h1[j] <= 0) num1++;
                if (h2[tmp] <= 0) num2++;
                h1[j] += at2[tmp];
                h2[tmp] += at1[j];
            }
            nu2[tmp]--;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> at1[i];
        h1[i] = at1[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> at2[i];
        h2[i] = at2[i];
    }
    if (n > m) {
        dfs(0, 1, n, m);
    } else if (n < m) {
        dfs(1, 1, n, m);
    } else {
        dfs(0, 0.5, n, m);
        dfs(1, 0.5, n, m);
    }
    cout << fixed << setprecision(10) << ans1 << '\n'
         << ans2 << '\n'
         << ans3;
}