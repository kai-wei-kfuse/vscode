#include <iostream>
#include <cstdio>
using namespace std;
int n, lg[1030], ans[10];
void dfs(int i, int s) //2
{
    if (i > n)
    {
        for (int p = 1; p <= n; p++)
            printf("%5d", ans[p]);
        cout << endl;
        return;
    }
    for (int ss = s; ss > 0; ss -= ss & (-ss)) //3
    {
        int temp = ss & (-ss); //4
        ans[i] = lg[temp];     //5
        dfs(i + 1, s - temp);  //6
    }
}
int main()
{
    cin >> n;
    lg[1] = 1;
    for (int i = 2; i <= n; i++)
        lg[1 << (i - 1)] = i; //1
    dfs(1, (1 << n) - 1);     //?????????????
    return 0;
}
