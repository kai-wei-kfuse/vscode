#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char s[200005];
int main()
{
    int n;
    cin >> n;
    int p;
    while(n--){
        int sum = 0;
        cin >> s + 1 >> p;
        int len = strlen(s + 1);
        //cout << len << endl;
        vector<int> vis[26];
        for (int i = 1; i <= len;i++){
            vis[s[i] - 'a'].push_back(i);
            sum += s[i] - 'a' + 1;
        }
        int ii = 25;
        while(sum>p){
            while(vis[ii].empty())
                ii--;
            vis[ii].pop_back();
            sum -= (ii + 1);
        }
        vector<pair<int, char> > ve;
        for (int i = 0; i < 26;i++){
            for(auto j:vis[i]){
                ve.push_back({j, i + 'a'});
            }
        }
        sort(ve.begin(), ve.end());
        for(auto i :ve)
            cout << i.second;
        cout << '\n';
    }
}