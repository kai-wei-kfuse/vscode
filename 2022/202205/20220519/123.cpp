#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;
struct xx {
    int x, y;
} a[100005];
int parent[100005];
int find(int x) {
    while (x != parent[x]) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void root(int x, int y) {
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_) {
        parent[x_] = y_;
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y;
            root(a[i].x, a[i].y);
        }
        int tmp;
        cin >> tmp;
        int w, a, b;
        for (int i = 1; i <= tmp; i++) {
            cin >> w >> a >> b;
        }
    }
    int i, j, k;
    queue<int> Q;
    set<int, int> se;
    map<int, int> mp;
    priority_queue<int, vector<int>, greater<int> > Q;
}