#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
typedef long long ll;
int a[1005];
int c[6];
int box[25];
stack<int> axx, bxx;
queue<int> cxx;
using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    int b = 0, cc = 0, tmp, aa = 1;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        axx.push(a[i]);
    }
    while (1) {
        flag = 0;
        if (cxx.empty()) {        //枝是空的
            if (bxx.empty()) {    //盒子空
                tmp = axx.top();  //推送器取
                cxx.front() = tmp;
                // cout << tmp << endl;
                axx.pop();
            } else {
                tmp = bxx.top();
                cxx.push_back(tmp);
                bxx.pop();
            }
        } else {                        //枝有叶子
            if (b > 0) {                //盒子不空
                if (box[b] <= c[cc]) {  //盒子最上面满足
                    c[++cc] = box[b];
                    box[b] = 0;
                    b--;
                } else {  //盒子不满足
                    tmp = a[aa];
                    if (tmp <= c[cc]) {  //推送器满足
                        c[++cc] = tmp;
                        aa++;
                    } else {  //推送器不满足
                        if (b < m) {
                            box[++b] = tmp;  //放盒子
                            aa++;
                        } else {       //盒子满了
                            flag = 1;  //做好了
                        }
                    }
                }
            } else {  //盒子空
                tmp = a[aa];
                // cout << tmp << endl;
                if (tmp <= c[cc]) {  //推送器满足
                    c[++cc] = tmp;
                    aa++;
                } else {  //推送器不满足
                    if (b < m) {
                        box[++b] = tmp;  //放盒子
                        // cout << tmp << endl;
                        aa++;
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
        if (flag || cc == l) {
            for (int i = 1; i <= cc; i++) {
                cout << c[i];
                if (i < cc)
                    cout << ' ';
            }
            cout << endl;
            cc = 0;
            flag = 0;
        }
        if (aa > n) {
            for (int i = 1; i <= cc; i++) {
                cout << c[i];
                if (i < cc)
                    cout << ' ';
            }
            break;
        }
    }
}