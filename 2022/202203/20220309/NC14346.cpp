#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int t;
    while(n--){
        set<int >a;
        cin>>t;
        for(int i=1;i<=t;i++){
            int x;
            cin>>x;
            a.insert(x);
        }
        cout<<a.size()<<endl;
    }
}