#include <iostream>
#include <string>
#include <set>
using namespace std;
const int MAX = 1e6 + 7;
int m, k;
struct cmp {
    bool operator () (const int& u, const int& v) const {
        return u < v;
    }
};
set<int,cmp> se;
//全局变量区

int main() {
    se.insert(10);
    se.insert(12);
    se.insert(15);
    se.insert(19);
    se.insert(14);
    for(set<int,cmp>::iterator i=se.begin();i!=se.end();i++){
        cout<<(*i)<<endl;
    }
    return 0;
}
//函数区