#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int ans;
char str1[233], str2[233];
int main() {
    scanf("%s", str1);
    scanf("%s", str2);
    for (int i = 0; i < strlen(str1); i++)
        for (int j = 1; j < strlen(str2); j++)
            if (str1[i] == str2[j] && str1[i + 1] == str2[j - 1])
                ans++;
    printf("%d", 1 << ans);
    return 0;
}