#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> tr(300005);
int n;
int lowbit(int x) {
    return x & (-x);
}
void add(int i) {
    while (i <= n) {
        tr[i]++;
        i += lowbit(i);
    }
}
int query(int i) {
    int res = 0;
    while (i) {
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}

signed main() {
    int k;
    cin >> n >> k;
    deque<int> qu;
    vector<int> ve(n + 1);
    int gr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        gr += query(n) - query(ve[i]);
        add(ve[i]);
    }
    cout << gr << endl;
    for (int i = 1; i <= n; i++) {
        qu.push_back(ve[i]);
    }
    string s;
    cin >> s;
    int flag = 1;
    for (int i = 0; i < k; i++) {
                if (s[i] == 'S') {
            if (flag) {
                int tmp = qu.front();
                gr = gr - (tmp - 1) + (n - tmp);
                qu.pop_front();
                qu.push_back(tmp);
            } else {
                int tmp = qu.back();
                gr = gr - (tmp - 1) + (n - tmp);
                qu.pop_back();
                qu.push_front(tmp);
            }
        } else {
            gr = n * (n - 1) / 2 - gr;
            flag ^= 1;
        }
        cout << gr % 10;
    }
    cout << endl;
}