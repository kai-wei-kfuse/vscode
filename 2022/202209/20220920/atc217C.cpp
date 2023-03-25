#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> ve(n+1);
    for (int i = 1; i <= n;i++){
        cin >> ve[i].first;
        ve[i].second = i;
    }
    sort(ve.begin() + 1, ve.end());
    for (int i = 1; i <= n;i++){
        cout << ve[i].second<<' ';
    }
}