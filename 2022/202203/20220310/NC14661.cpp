#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int >a;
int main()
{
    int n,t;
    cin>>n>>t;
    while(t--){
        int c,x;
        cin>>c;
        if(c==1){
            cin>>x;
            a.insert(a.begin(),x);
        }
        if(c==2){
            a.erase(a.begin());
        }
        if(c==3){
            cin>>x;
            a.push_back(x);
            }
        if(c==4){
            a.erase(a.end()-1);
        }
        if(c==5){
            reverse(a.begin(),a.end());
        }
        if(c==6){
            cout<<a.size()<<endl;
            vector<int >::iterator i=a.begin();
            while(i!=a.end()){
                cout<<(*i)<<' ';
                i++;
            }
            cout<<' '<<endl;
        }
        if(c==7){
            sort(a.begin(),a.end());
        }
    }
}