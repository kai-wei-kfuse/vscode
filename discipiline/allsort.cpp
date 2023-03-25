#include <iostream>
#include <cstring>
using namespace std;
string a;
int b[7];
int ans[7];
int len;
bool vis[7];
void dfs(int x)
{
    if (x > len){
        for(int k = 1; k <= len; k++)cout <<(char)(ans[k]+'a');
        cout<<endl;
        return;
    }
    for(int i = 1; i <= len; i++){
        if(vis[i]==0)
        {
            vis[i]=1;
            ans[x]=b[i];
            dfs(x+1);
            vis[i]=0;
        }
    }
    return ;
}
int main()
{
    cin >> a;
    len = a.length();
    for (int i = 1; i <= len; i++)
    {
        b[i] = (int)a[i - 1] - 'a';
    }
    dfs(1);
}