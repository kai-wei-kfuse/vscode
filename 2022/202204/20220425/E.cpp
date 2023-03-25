#include <iostream>
using namespace std;
int main() {
    freopen("easy.in", "r", stdin);  //输入重定向，输入数据将从in.txt文件中读取
    freopen("easy.out", "w", stdout);  //输出重定向，输出数据将保存out.txt文件中
    string a;
    cin >> a;
    string b = "";
    int len = a.length();
    for (int i = 0; i < len; i++) {
        b += a[i];
        if (a[i] == '-') {
            i++;
            b += a[i];
            i++;
            int flag = 0;
            while (a[i] >= '0' && a[i] <= '9') {
                if (flag == 0)
                    b += '+';
                if (a[i] == '0') {
                    // b += '+';
                    b += a[i];
                    i++;
                } else {
                    flag = 1;
                    b += a[i];
                    i++;
                }
            }
            i--;
        }
    }
    cout << b;
}