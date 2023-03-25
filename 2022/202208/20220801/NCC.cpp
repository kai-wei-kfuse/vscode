#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int N = 3 * n;
        map<int, pair<int, int> > mp;
        vector<int> ve(n);
        int tmp;
        string s;
        for (int i = 1; i <= N; i++) {
            cin >> tmp >> s;
            if (s == "YES") {
                mp[tmp].first++;
            } else {
                mp[tmp].second++;
            }
        }
        if (mp.size() < n) {
            cout << "-1";  //没有查询所有位置输出-1
        } else {
            int have_mistake = 0;
            for (auto i : mp) {  //全对
                if (i.second.first == 1 || i.second.second == 1) {
                    // YES:NO=1:1,0:1,1:0则无法确定是否全对
                    //全都是2:0,x:0,0:2,0:x才全对
                    have_mistake = 1;
                }
            }
            if (have_mistake) {
                int flag = 0;
                for (auto i : mp) {  //有问题找异常
                    if (i.second.first > 0 && i.second.second > 0) {
                        // YES ,NO都大于零
                        if (i.second.first > 1 && i.second.second == 1) {
                            // YES大于1,NO==1
                            ve[i.first] = 1;
                            flag = 1;
                        } else if (i.second.first == 1 && i.second.second > 1) {
                            // NO大于1,YES==1
                            ve[i.first] = -1;
                            flag = 1;
                        }
                    }
                }
                if (flag) {  //存在可发现异常
                    for (auto i : mp) {
                        if (ve[i.first] == 0) {
                            if (i.second.first > 0) {  // YES>0
                                ve[i.first] = 1;
                            } else if (i.second.second > 0) {  // NO>0
                                ve[i.first] = -1;
                            }
                        }
                    }
                    for (auto i : ve) {
                        if (i == 1)
                            cout << i;
                        else
                            cout << '0';
                    }
                } else {  //不存在可发现异常
                    cout << "-1";
                }
            } else if (have_mistake == 0) {
                for (auto i : mp) {
                    if (ve[i.first] == 0) {
                        if (i.second.first > 0) {  // YES>0
                            ve[i.first] = 1;
                        } else if (i.second.second > 0) {  // NO>0
                            ve[i.first] = -1;
                        }
                    }
                }
                for (auto i : ve) {
                    if (i == 1)
                        cout << i;
                    else
                        cout << '0';
                }
            }
        }
        cout << '\n';
    }
}
/*
3
0 NO
1 YES
2 YES
0 YES
1 YES
2 YES
0 YES
1 YES
2 YES
*/