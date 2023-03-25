#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string s[30005];
const int N = 300005;
int son[N][26], vis[N], idx, cnt[N], in[N];
vector<int> edge[30];
vector<string>ans;

void insert_(string s, int len) {
    int p = 0;
    for (int i = 0; i < len; i++) {
        int str = s[i] - 'a';
        if (!son[p][str])
            son[p][str] = ++idx;
        p = son[p][str];
    }
    cnt[p]++;
}

int build(string s, int len) {
    int p = 0;//0没有字母所以初始化为1
    for (int i = 0; i < len; i++) {
        int str = s[i] - 'a';
        if (cnt[p])
            return 0;
        for (int u = 0; u < 26; u++) {
            if (son[p][u] && u != str) {
                edge[u].push_back(str);
                in[str]++;
            }
        }
        p = son[p][str];
    }
    return 1;
}

int chack(string s, int len) {
    for (int i = 0; i < 26;i++) {
        edge[i].clear();
        in[i] = 0;
    }
        if (build(s, len)) {
            queue<int> Q;
            int num = 0;
            for (int i = 0; i < 26; i++) {
                if (!in[i]) {
                    Q.push(i);  //第一步，遍历所有点，把入度为0的加入队列s
                }
            }
            while (!Q.empty()) {
                int p = Q.front();  //第二步，取出点
                Q.pop();            //取出来之后就不需要他了
                for (int i = 0; i < edge[p].size(); i++) {
                    int u = edge[p][i];
                    in[u]--;
                    if (!in[u])
                        Q.push(u);
                }
            }
            for (int i = 0; i < 26; i++) {
                if (in[i])
                    return 0;
            }
            return 1;
        }
        else
            return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        int len = s[i].size();
        insert_(s[i], len);
    }
    for (int i = 1; i <= n; i++) {
        int len = s[i].length();
        //cout << s[i] <<'|'<< endl;
        
        if (chack(s[i], len)) {
            ans.emplace_back(s[i]);
        }
    }
    cout << ans.size()<<'\n';
    for(auto i:ans)
        cout << i << '\n';
}