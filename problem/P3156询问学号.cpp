#include<iostream>//可变数组vector
#include<vector>
using namespace std;
int main()
{
    int tmp,n,m;
    cin>>n>>m;
    vector < int > stu;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        stu.push_back(tmp);
    }
    for(int i=0;i<m;i++)
    {
        cin>>tmp;
        cout<<stu[tmp-1]<<endl;
    }
}