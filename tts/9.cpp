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
        if (cxx.empty()) {        //֦�ǿյ�
            if (bxx.empty()) {    //���ӿ�
                tmp = axx.top();  //������ȡ
                cxx.push(tmp);
                // cout << tmp << endl;
                axx.pop();
            } else {
                tmp = bxx.top();
                cxx.push(tmp);
                bxx.pop();
            }
        } else {                                //֦��Ҷ��
            if (!bxx.empty()) {                 //���Ӳ���
                if (bxx.top() <= cxx.back()) {  //��������������
                    cxx.push(bxx.top());
                    bxx.pop();
                } else {  //���Ӳ�����
                    tmp = axx.top();
                    if (tmp <= cxx.back()) {  //����������
                        cxx.push(tmp);
                        axx.pop();
                    } else {  //������������
                        if (bxx.size() < m) {
                            bxx.push(tmp);  //�ź���
                            axx.pop();
                        } else {       //��������
                            flag = 1;  //������
                        }
                    }
                }
            } else {  //���ӿ�
                tmp = axx.top();
                // cout << tmp << endl;
                if (tmp <= cxx.back()) {  //����������
                    cxx.push(tmp);
                    axx.pop();
                } else {  //������������
                    if (bxx.size() < m) {
                        bxx.push(tmp);  //�ź���
                        // cout << tmp << endl;
                        axx.pop();
                    } else {       //��������
                        flag = 1;  //������
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