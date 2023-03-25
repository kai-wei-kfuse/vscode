
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        s[i][j] = a[i][j];
    }
}
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        s[i][j] += s[i - 1][j];
    }
}
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        s[i][j] += s[i][j - 1];
    }
}