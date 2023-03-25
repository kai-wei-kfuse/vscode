#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<queue<int> > box(m + 1);
    vector<vector<int> > a(n + 1);  //第一维是颜色，第二维是第几个盒子
    queue<int> Q;                   //取球队列，含义是颜色
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int tmp;
            cin >> tmp;
            box[i].push(tmp);  //用队列储存
        }
        a[box[i].front()].push_back(i);  //把第一个放进二维数组
    }
    for (int i = 1; i <= n; i++) {
        if (a[i].size() == 2) {  //如果有某个颜色可以拿两个就放进队列
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int now = Q.front();  //颜色取出来
        // cout << now << endl;
        Q.pop();
        for (auto p : a[now]) {
            box[p].pop();
            // int f_color = box[f_id].front();
            // cout << f_id << ' ' << f_color << endl;
            if (!box[p].empty()) {
                a[box[p].front()].push_back(p);
                if (a[box[p].front()].size() == 2)
                    Q.push(box[p].front());
            }

            // int s_id = a[now][1];
            // box[s_id].pop();
            // // int s_color = box[s_id].front();
            // // cout << s_id << ' ' << s_color << '|' << endl;
            // if (!box[s_id].empty()) {
            //     a[box[s_id].front()].push_back(s_id);
            //     if (a[box[s_id].front()].size() == 2)
            //         Q.push(box[s_id].front());
            //
            // }
        }
    }
    int flag = 0;
    for (auto i : box) {
        if (i.size() != 0)
            flag = 1;
    }
    if (flag == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}