#include <iostream>
using namespace std;
int n;
pair<int, int> p[200];
pair<int, int> tree[200];
void build_tree(int node, int l, int r) {
    if (l == r) {
        tree[node] = p[l];
        return;
    }
    int mid = (r + l) >> 1;
    build_tree(node << 1 | 1, mid + 1, r);
    build_tree(node << 1, l, mid);
    if (tree[node << 1].first > tree[node << 1 | 1].first)
        tree[node] = tree[node << 1];
    else
        tree[node] = tree[node << 1 | 1];
}
int main() {
    cin >> n;
    for (int i = 1; i <= (1 << n); i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    build_tree(1, 1, (1 << n));
    if (tree[2].first < tree[3].first)
        cout << tree[2].second;
    else {
        cout << tree[3].second;
    }
}