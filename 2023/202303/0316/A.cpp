#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int ,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second < b.second;
    }else{
        return a.first > b.first;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    map < int, vector<pair<int, int> > > mp;
    for (int i = 1; i <= n; i++) {
        int c, b;
        cin >> c >> b;
        mp[c].push_back({b, i});
    }
    for(auto i:mp){
        sort(i.second.begin(), i.second.end(),cmp);
        cout << i.second[0].second<<" ";
    }
}