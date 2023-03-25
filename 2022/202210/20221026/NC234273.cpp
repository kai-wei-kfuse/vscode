#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int tr[maxn][26];  //字典树
int idx = 0;       //字典树节点编号
int cnt[maxn];     //字典树标记数组
int fail[maxn];    //失配指针（next数组）
int id[maxn];      //统计数组
vector<int> v;     //拓扑排序结果

void insert(string s, int x) {  //构建字典树（基本操作）
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int tmp = s[i] - 'a';
        if (!tr[p][tmp])
            tr[p][tmp] = ++idx;
        p = tr[p][tmp];
        // cnt[p]++;
    }
    // cnt[p]++;//在这里的cnt数组是为了标记结尾相同的串的个数
    id[x] = p;  //记录这个串末尾的节点
    // id[p] = x;//记录p节点的串是哪个
}
void build() {  //构建AC自动机
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (tr[0][i])
            q.push(tr[0][i]);  //把第一层插入队列
    }
    while (!q.empty()) {
        int tmp = q.front();
        v.push_back(tmp);
        q.pop();
        for (int i = 0; i < 26; i++) {
            int p = tr[tmp][i];
            if (!p)
                tr[tmp][i] = tr[fail[tmp]][i];
            //如果不存在这个节点，就使他直接变成失配指针指向的节点
            else {
                fail[p] = tr[fail[tmp]][i];
                //如果存在就更新失配指针，指向父节点的失配指针指向的节点的同一个字母，如果不存在，则继续往上跳
                //往上跳的操作由 不存在时更新节点 来保证
                q.push(p);  //存在就放入队列，不存在就不放
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> str;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        str.push_back(s);
        insert(s, i);
    }
    build();
    string a;
    cin >> a;
    // int res = 0;
    //----------------------------
    int len = a.length();
    // for (int i = 0, j = 0; i < len; i++) {
    //     int tmp = a[i] - 'a';
    //     j = tr[j][tmp];
    //     int p = j;
    //     while (p && cnt[p] != -1) {
    //         res += cnt[p];
    //         cnt[p] = -1;
    //         p = fail[p];
    //     }
    // }
    //------------------------------
    int maxn = 0;
    int p = 0;
    for (int i = 0; i < len; i++) {//录入文本串
        int tmp = a[i] - 'a';
        p = tr[p][tmp];
        cnt[p]++;
    }
    len = v.size();
    for (int i = len - 1; i >= 0; i--) {
        cnt[fail[v[i]]] += cnt[v[i]];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[id[i]] << endl;
        // maxn = max(maxn, cnt[i]);
    }
    // cout << maxn << endl;
    // for (int i = 1; i <= idx;i++){
    //     if(cnt[i]==maxn){
    //         cout << str[id[i]] << endl;
    //     }
    // }
    // cout << res << endl;
}