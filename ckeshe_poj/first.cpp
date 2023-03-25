#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct node {
    int id;
    double num;
    string name;
};
int n;
vector<node> ve(31);
map<string, int> mp;
vector<int> edge[31], see[31], ins(31, 0);

void init() {
    //打开 in.txt 文件，等待读取
    ifstream fin("in.txt");
    streambuf* oldcin;
    //用 rdbuf() 重新定向，返回旧输入流缓冲区指针
    oldcin = cin.rdbuf(fin.rdbuf());
    int k, tmp;
    cin >> n;
    double num;
    string name, s;
    for (int i = 1; i <= n; i++) {
        cin >> k >> name >> num >> tmp;
        ve[i] = {k, num, name};
        mp[name] = i;
        edge[i].clear();
        for (int j = 1; j <= tmp; j++) {
            cin >> s;
            edge[mp[s]].push_back(i);
            ins[i]++;
            see[i].push_back(mp[s]);
        }
    }
    cin.rdbuf(oldcin);
    fin.close();
}

void printout() {
    cout << "目前课程信息:" << endl;
    cout << "编号 "
         << " 课程名称       "
         << " 学分 "
         << " 先修课程 " << endl;
    for (int i = 1; i <= n; i++) {
        printf("%-3d", i);
        printf("%-20s", ve[i].name.c_str());
        // cout << ve[i].name << ' ';
        //  cout << ve[i].num << ' ';
        printf("%3.1f ", ve[i].num);
        if (see[i].size()) {
            for (auto x : see[i]) {
                cout << ve[i].name << ' ';
            }
        }
        cout << endl;
    }
}

void torport() {
    cout << "请输入每学期学分上限分配课程：";
    double lim = 0;
    cin >> lim;
    queue<int> q;
    vector<int> list;
    for (int i = 1; i <= n; i++) {
        if (ins[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        list.push_back(u);
        q.pop();
        for (auto i : edge[u]) {
            if (!--ins[i]) {
                q.push(i);
            }
        }
    }
    double cnt = 0;
    int tmp = 0;
    for (auto i : list) {
        if (cnt + ve[i].num > lim) {
            cout << "总学分：" << cnt;
            cnt = 0;
        }
        if (cnt == 0) {
            cout << endl
                 << "第" << ++tmp << "学期: ";
        }
        cout << ve[i].name << " ";
        cnt += ve[i].num;
    }
    cout << "总学分：" << cnt;
    cout << endl;
}
void torport2() {
    cout << "请输入分配的学期数：";
    int lim = 0;
    cin >> lim;
    int flag = n % lim;
    lim = n / lim;
    queue<int> q;
    vector<int> list;
    for (int i = 1; i <= n; i++) {
        if (ins[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        list.push_back(u);
        q.pop();
        for (auto i : edge[u]) {
            if (!--ins[i]) {
                q.push(i);
            }
        }
    }
    double cnt = 0;
    int tmp = 0, now = 0;
    for (auto i : list) {
        if (flag > 0) {
            if (now > lim) {

                cout <<"课程数量:"<<now<< " 总学分：" << cnt;
                cnt = 0;
                now = 0;
                flag--;
            }
        } else {
            if (now >= lim) {
                cout <<"课程数量:"<<now<< " 总学分：" << cnt;
                cnt = 0;
                now = 0;
            }
        }
        if (cnt == 0) {
            cout << endl
                 << "第" << ++tmp << "学期: ";
        }
        cout << ve[i].name << " ";
        cnt += ve[i].num;
        now++;
    }
    cout <<"课程数量:"<<now<<" 总学分：" << cnt;
    cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);  //输入重定向，输入数据将从in.txt文件中读取
    // freopen("out.txt", "w", stdout);
    // //输出重定向，输出数据将保存out.txt文件中
    init();
    printout();
    Sleep(200);
    // fclose(stdin);//关闭重定向输入
    cout << "[1]按学分上限分配课程" << endl;
    cout << "[2]按学期数量分配课程" << endl;
    int tmp;
    cin >> tmp;
    if (tmp == 1) {
        torport();
    } else {
        torport2();
    }
}