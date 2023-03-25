#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int a[1005];
int c[6];
int box[25];

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    int b = 0, cc = 0, tmp, aa = 1;
    int flag = 0;
    stack<int> axx, bxx;
    queue<int> cxx;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        axx.push(a[i]);
    }
    while (1) {
        flag = 0;
        if (cxx.empty()) {        //枝是空的
            if (bxx.empty()) {    //盒子空
                tmp = axx.top();  //推送器取
                cxx.push(tmp);
                // cout << tmp << endl;
                axx.pop();
            } else {
                tmp = bxx.top();
                cxx.push(tmp);
                bxx.pop();
            }
        } else {                                //枝有叶子
            if (!bxx.empty()) {                 //盒子不空
                if (bxx.top() <= cxx.back()) {  //盒子最上面满足
                    cxx.push(bxx.top());
                    bxx.pop();
                } else {  //盒子不满足
                    tmp = axx.top();
                    if (tmp <= cxx.back()) {  //推送器满足
                        cxx.push(tmp);
                        axx.pop();
                    } else {  //推送器不满足
                        if (bxx.size() < m) {
                            bxx.push(tmp);  //放盒子
                            axx.pop();
                        } else {       //盒子满了
                            flag = 1;  //做好了
                        }
                    }
                }
            } else {  //盒子空
                tmp = axx.top();
                // cout << tmp << endl;
                if (tmp <= cxx.back()) {  //推送器满足
                    cxx.push(tmp);
                    axx.pop();
                } else {  //推送器不满足
                    if (bxx.size() < m) {
                        bxx.push(tmp);  //放盒子
                        // cout << tmp << endl;
                        axx.pop();
                    } else {       //盒子满了
                        flag = 1;  //做好了
                    }
                }
            }
        }
        // for (int i = 1; i <= cc; i++) {
        //     cout << c[i] << ' ';
        // }
        // cout << endl;
        if (flag || cxx.size() == l) {
            for (int i = 1; i <= l; i++) {
                cout << cxx.front();
                cxx.pop();
                if (i < l)
                    cout << ' ';
            }
            cout << endl;
            flag = 0;
        }
        if (axx.empty()) {
            int xx = cxx.size();
            for (int i = 1; i <= xx; i++) {
                cout << cxx.front();
                cxx.pop();
                if (i < xx)
                    cout << ' ';
            }
            break;
        }
    }
}