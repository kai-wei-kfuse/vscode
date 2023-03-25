#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> q(100005);
int main(){
    int n;
    cin>>n;
    vector<int> ve(n+1);
    for (int i = 1; i <= n;i++){
        cin >> ve[i];
    }
    int len = 0;
    for (int i = 1; i <= n;i++){
        int l = 0, r = len;
        while(l<r){
            int mid = r + l + 1 << 1;
            if(q[mid]<ve[i])
            {
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        len = max(len, r+1);
        q[r + 1] = ve[i];
    }
    cout << len;
}