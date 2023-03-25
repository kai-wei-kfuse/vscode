#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> ans;

void dfs(ll x, ll mul) {
    while (x % 2 == 0) {
        mul *= 2;
        x /= 2;
    }
    while (x % 3 == 0) {
        mul *= 3;
        x /= 3;
    }

    if (x == 1) {
        ans.push_back(mul);
    } else {
        ll i = 3;
        for (; i * 3 < x; i *= 3) {
        }
        ans.push_back(mul * i);
        dfs(x - i, mul);
    }
}

int main() {
    // freopen("distribution.in", "r", stdin);
    // freopen("distribution.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        ans.clear();
        ll n;
        scanf("%lld", &n);
        dfs(n, 1);
        printf("%lu\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
