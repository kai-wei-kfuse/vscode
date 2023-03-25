#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define PII pair<int, int>

priority_queue<PII, vector<PII>, greater<PII> > Q;
int main() {
    int n;
    cin >> n;
   /*  vector<PII> ve(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> ve[i].second;
    }
    for (int i = 0; i < n; i++) {
        Q.push({ve[i].second, i});
        // Q.push({ve[i].second+ve[i].first, i + 1});
    }
    int cnt = 0;
    map<int, int> mp;
    while (cnt < n) {
        int id = Q.top().second;
        int time = Q.top().first;
        Q.pop();
        // cout << id<< ' ' << time<< endl;
        if (mp[id] == 0) {
            cnt++;
            mp[id] = time;
        }
        Q.push({ve[id].first + time, (id + 1) % n});
    }
    for (auto i : mp) {
        cout << i.second << endl;
    } */
    // vector<int> s(n ),t(n);
    // for (int i = 0; i < n;i++){
    //     cin >> s[i];
    // }
    // for (int i = 0; i < n;i++){
    //     cin >> t[i];
    // }

}