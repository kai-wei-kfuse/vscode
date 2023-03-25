#include<iostream>
#include<set>
/*
set的操作：
*/
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c,len;
    set<int>wood;
    while(n--){
     cin>>c>>len;
     if(c==1){
         if(wood.find(len)!=wood.end())cout<<"Already Exist"<<endl;
         wood.insert(len);
     }   
     else if(wood.empty())cout<<"Empty"<<endl;
     else{
         set<int >::iterator i=wood.lower_bound(len),j=i;
         if(j!=wood.begin())j--;
         if(i!=wood.end() && len-(*j)>(*i)-len)j=i;
         cout<<(*j)<<endl;wood.erase(j);
     }
     
    }
}