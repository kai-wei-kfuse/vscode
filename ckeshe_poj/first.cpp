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
    //�� in.txt �ļ����ȴ���ȡ
    ifstream fin("in.txt");
    streambuf* oldcin;
    //�� rdbuf() ���¶��򣬷��ؾ�������������ָ��
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
    cout << "Ŀǰ�γ���Ϣ:" << endl;
    cout << "��� "
         << " �γ�����       "
         << " ѧ�� "
         << " ���޿γ� " << endl;
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
    cout << "������ÿѧ��ѧ�����޷���γ̣�";
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
            cout << "��ѧ�֣�" << cnt;
            cnt = 0;
        }
        if (cnt == 0) {
            cout << endl
                 << "��" << ++tmp << "ѧ��: ";
        }
        cout << ve[i].name << " ";
        cnt += ve[i].num;
    }
    cout << "��ѧ�֣�" << cnt;
    cout << endl;
}
void torport2() {
    cout << "����������ѧ������";
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

                cout <<"�γ�����:"<<now<< " ��ѧ�֣�" << cnt;
                cnt = 0;
                now = 0;
                flag--;
            }
        } else {
            if (now >= lim) {
                cout <<"�γ�����:"<<now<< " ��ѧ�֣�" << cnt;
                cnt = 0;
                now = 0;
            }
        }
        if (cnt == 0) {
            cout << endl
                 << "��" << ++tmp << "ѧ��: ";
        }
        cout << ve[i].name << " ";
        cnt += ve[i].num;
        now++;
    }
    cout <<"�γ�����:"<<now<<" ��ѧ�֣�" << cnt;
    cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);  //�����ض����������ݽ���in.txt�ļ��ж�ȡ
    // freopen("out.txt", "w", stdout);
    // //����ض���������ݽ�����out.txt�ļ���
    init();
    printout();
    Sleep(200);
    // fclose(stdin);//�ر��ض�������
    cout << "[1]��ѧ�����޷���γ�" << endl;
    cout << "[2]��ѧ����������γ�" << endl;
    int tmp;
    cin >> tmp;
    if (tmp == 1) {
        torport();
    } else {
        torport2();
    }
}