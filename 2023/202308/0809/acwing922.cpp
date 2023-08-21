#include <bits/stdc++.h>
using namespace std;

struct xx {
    int x, id, dis;
};

vector<xx> edge[505];

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    getline(cin, s);
    for (int j = 1; j <= n; j++) {
        getline(cin, s);
        stringstream ss(s);
        int tmp, ls;
        ss >> ls;
        while (ss >> tmp) {
            // cout << ls << ' ' << tmp << endl;
            edge[ls].push_back({tmp, j});
            ls = tmp;
        }
    }
    deque<xx> q;
    q.push_back({1, 0, 0});
    while (!q.empty()) {
        xx pos = q.front();
       // cout << pos.x << ' ' << pos.id << ' ' << pos.dis << endl;
        if (pos.x == m) {cout << pos.dis << endl;
            return 0;
        }
        q.pop_front();
        for (auto [x, id, dis] : edge[pos.x]) {
            if (pos.x == 1) {
                q.push_front({x, id, pos.dis});
            } else if (pos.id == id) {
                q.push_front({x, id, pos.dis});
            } else {
                q.push_back({x, id, pos.dis + 1});
            }
        }
    }
    cout << "NO" << endl;
}