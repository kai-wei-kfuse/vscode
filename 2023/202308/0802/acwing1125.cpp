#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> dist(200, vector<double>(200, 0x3f3f3f3f));
double mxdis[200];
double dis(pair<int, int> a, pair<int, int> b) {
    int x = a.first, y = a.second, xx = b.first, yy = b.second;
    return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i].first >> ve[i].second;
    }
    vector<vector<char>> edge(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> edge[i][j];
            if (edge[i][j] == '1')
                dist[i][j] = dis(ve[i], ve[j]);
            else if (i == j)
                dist[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != 0x3f3f3f3f) {
                mxdis[i] = max(mxdis[i], dist[i][j]);
                ans = max(ans, mxdis[i]);
            }
        }
    }
    double res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == 0x3f3f3f3f) {
                res = min(res, mxdis[i] + mxdis[j] + dis(ve[i], ve[j]));
            }
        }
    }
    cout << fixed << setprecision(6) << max(ans, res) << endl;
}