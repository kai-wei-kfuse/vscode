#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
string a;
int main()
{
    int n,k;
    cin>>n>>k;
    set<int > m;
    while(n--){
        cin>>a;
        if(a=="add"){
            int tmp;
            cin>>tmp;
            m.insert(tmp);
            set<int >::iterator p=m.lower_bound(tmp),j=p;
            while(--p!=m.begin()){
                if(abs(tmp-(*p))<=k){
                    m.erase(j);
                    break;
                }
                if(abs(tmp-(*p))>=k)break;
            }
            p=j;
            while(++p!=m.end()){
                if(abs(tmp-(*p))<=k){
                    m.erase(j);
                    break;
                }
                if(abs(tmp-(*p))>=k)break;
            }
        }
        if(a=="del"){
            int tmp;
            cin>>tmp;
            m.insert(tmp);
            set<int >::iterator p=m.lower_bound(tmp),j=p,q=p;
            p--;q++;
            while(abs(tmp-(*p))<=k){
                if(abs(tmp-(*p))>k)p++;
                p--;
                
            }
            while(abs(tmp-(*q))<=k){
                if(abs(tmp-(*q))>k)q--;
                q++;
            }
            m.erase(p,q);
        }
        if(a=="query"){
         int tmp;
            cin>>tmp;
            m.insert(tmp);
            set<int >::iterator p=m.lower_bound(tmp),j=p,q=p;
            while(--p!=m.begin()){
                if(abs(tmp-(*p))<=k){
                    break;
                }
                if(abs(tmp-(*p))>=k)break;
            }
            p=j;
            while(++p!=m.end()){
                if(abs(tmp-(*p))<=k){
                    m.erase(j);
                    break;
                }
                if(abs(tmp-(*p))>=k)break;
            }
        }
    }
}