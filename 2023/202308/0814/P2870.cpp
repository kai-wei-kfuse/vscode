#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

struct SA {
    string s;
    int sa[N], cnt[N], t1[N], t2[N], rk[N], height[N];
    int n;
    void build_sa() {
        int m = 128;  // 字符集大小，这里是ASCII码，如果是小写字母，就是26
        int *x = t1, *y = t2;
        n++;
        for (int i = 0; i < m; i++)
            cnt[i] = 0;  // 初始化 cnt数组
        // 进行第一轮计数排序
        for (int i = 0; i < n; i++)
            cnt[x[i] = s[i]]++;
        for (int i = 1; i < m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--cnt[x[i]]] = i;

        for (int k = 1; k <= n; k <<= 1) {
            int p = 0;
            // 进行对第二关键字基数排序
            for (int i = n - k; i < n; i++)
                y[p++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= k) y[p++] = sa[i] - k;
            // 进行对第一关键字基数排序
            for (int i = 0; i < m; i++)
                cnt[i] = 0;
            for (int i = 0; i < n; i++)
                cnt[x[y[i]]]++;
            for (int i = 1; i < m; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--cnt[x[y[i]]]] = y[i];
            swap(x, y);  // 交换x和y
            p = 1;
            x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if (p >= n) break;
            m = p;
        }
        int k = 0;
        n--;
        for (int i = 0; i <= n; i++)
            rk[sa[i]] = i;
        for (int i = 0; i < n; i++) {
            // if(rk[i] == 0) continue;
            if (k) k--;
            int j = sa[rk[i] - 1];
            while (s[i + k] == s[j + k])
                k++;
            height[rk[i]] = k;
        }
    }

    // void get_height() {
        
    // }

    int RMQ[N][20], Log[N];
    void initRMQ(int n) {
        for (int i = 2; i <= n; i++) {
            Log[i] = Log[i >> 1] + 1;
        }
        for (int i = 1; i <= n; i++)
            RMQ[i][0] = height[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r) {
        int k = Log[r - l + 1];
        return min(RMQ[l][k], RMQ[r - (1 << k) + 1][k]);
    }

    int lcp(int x, int y) {
        x = rk[x], y = rk[y];
        if (x > y)
            swap(x, y);
        return query(x + 1, y);  // 返回sa[x]和sa[y]的最长公共前缀
    }

} sa_;
int main() {
    cin>>sa_.n;
    int len=sa_.n;
   // string s;
    for(int i=0;i<sa_.n;i++){
        char x;
        cin>>x;
        sa_.s.push_back(x);
    }
   // s=sa_.s;
    sa_.s.push_back('0');
    for(int i=sa_.n-1;i>=0;i--){
        sa_.s.push_back(sa_.s[i]);
    }
   // cout<<sa_.s<<endl;
    sa_.n=sa_.s.size();
    sa_.build_sa();
    string ans="";
    int l=0,r=len-1;
    while(l<r){
        if(sa_.rk[l]<sa_.rk[len+len-r]){
            ans.push_back(sa_.s[l]);
            l++;
        }else{
            //cout<<r<<endl;
            ans.push_back(sa_.s[r]);
            r--;
        }
    }
    ans.push_back(sa_.s[l]);
    int lenx=ans.size();
    for(int i=0;i<len;i++){
        if(i%80==0&&i!=0)
            cout<<endl;
        cout<<ans[i];
    }
    //cout<<ans<<endl;
}