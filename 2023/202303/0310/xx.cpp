int flag = 0;  // ans表示最后有几种素数
for (int i = 1; prime[i] <= res / prime[i]; i++) {
    while (res % prime[i] == 0) {
        res /= prime[i];
        flag = 1;  // cout<<prime[i]<<endl;
    }
    if (flag)
        ans++;
    flag = 0;
}