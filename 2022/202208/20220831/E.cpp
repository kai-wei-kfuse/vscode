#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

struct xx {
    int x, i,f;
} sco[400005];
int mp[200005], mp1[200005];

bool cmp(xx a, xx b) {
    if(a.x==b.x)
        return a.f > b.f;
    return a.x > b.x;
}

int main() {
    int t;
    cin >> t;
    int c = 1;
    while (t--) {
        int n, p;
        cin >> n >> p;
        //map<int, int> mp, mp1;
        for (int i = 1, j = 0; i <= n; i++) {
            cin >> sco[++j].x;
            sco[j].i = i;
            sco[j].f = 1;
            cin >> sco[++j].x;
            sco[j].i = i;
            sco[j].f = 0;
            mp[i] = 0;
        }
        sort(sco + 1, sco + 1 + 2 * n, cmp);
        int tot = 0, ans = 0;
        for (int head = 1, tail = 1; head <= 2 * n; head++) {
            while (sco[head].x * 1LL * p <=
                   sco[tail].x * 1LL * 100) {  //及格线以内
                // cout <<sco[tail].i<<':'<< mp[sco[tail].i] << endl;
                if (mp[sco[tail].i] == 0)
                    tot++;
                mp[sco[tail].i]++;
                tail++;
            }
            // cout << sco[head].x << ' ' << tail << endl;
            ans = max(ans, tot);
            if (sco[head].f == 0) {
                break;
            }

            if (mp[sco[head].i] == 1)
                tot--;
            mp[sco[head].i]--;
            mp1[sco[head].i]--;
        }
        cout << "Case #" << c << ": " << ans << endl;
        c++;
    }
}