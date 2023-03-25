#include<iostream>
#include<map>
/*
map操作：
*/
using namespace std;
int main()
{
    int n,c;
    cin>>n;
    string name;
    int sum=0;
    map < string,int > st;
    while(n--){
        cin>>c;
        if(c==1){
            int sc;
            cin>>name>>sc;
            st[name]=sc;
            cout<<"OK"<<endl;
        }
        if(c==2){
            cin>>name;
            if(st.find(name)!=st.end())cout<<st[name]<<endl;
            else cout<<"Not found"<<endl;
        }
        if(c==3){
            cin>>name;
            if(st.find(name)==st.end())cout<<"Not found"<<endl;
            else {
                st.erase(st.find(name));
                cout<<"Deleted successfully"<<endl;
            }
        }
        if(c==4){
            cout<<st.size()<<endl;
        }
    }
}