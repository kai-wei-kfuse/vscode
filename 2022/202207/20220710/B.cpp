#include<iostream>
#include<map>
using namespace std;
map<char, int> mp;
int main()
{
    int n;
    cin>>n;
    string a;
    int ans = 0;
    for (int i = 1; i <= n;i++){
        cin >> a;
        ans = 0;
        int len = a.length() - 1;
        for (int i = 0 ; i <= len;i++){
            mp[a[i]]=1;
            if(mp.size()>3){
                //cout << i << endl;
                mp.clear();
                mp[a[i]]=1;
                ans++;
            }
        }
        mp.clear();
        cout << ans+1 << '\n';
    }
}