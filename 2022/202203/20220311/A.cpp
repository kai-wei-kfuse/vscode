#include<iostream>//Madoka and Math Dad
#include<vector>
using namespace std;
vector<int>a[500];

int main()
{
    int n;
    cin>>n;
    while(n--){
        int x;
        vector<int >b;
        cin>>x;
        if(x==1){cout<<'1'<<endl;
        continue;
        }
        if(x==2){cout<<'2'<<endl;
        continue;
        }
        for(int i=1,j=1;i<=x;j==3?j=1:j++,i++){
            if(j==1)
            b.insert(b.begin(),1);
            if(j==2){
            b.erase(b.begin());
            b.push_back(2);}
            if(j==3)
            b.push_back(1);
        }
        for(vector<int>::iterator p = b.begin();p!=b.end();p++){
            cout<<(*p);
        }
        cout<<endl;
    }
}