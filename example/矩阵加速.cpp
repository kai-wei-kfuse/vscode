#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int Mod = 1e9+7;
int T, n;
struct mat{
	LL m[5][5];
}Ans, base;
inline void init() {
	memset(Ans.m, 0, sizeof(Ans.m));
	for(int i=1; i<=3; i++) 
        Ans.m[i][1] = 1;//初始化初始矩阵
	memset(base.m, 0, sizeof(base.m));
	base.m[1][1] = base.m[1][3] = base.m[2][1] = base.m[2][2] = base.m[2][3] = base.m[3][1] =1;
    base.m[3][3] = 2;base.m[3][2]=1;//初始化递推矩阵
}
inline mat mul(mat a, mat b) {
	mat res;
	memset(res.m, 0, sizeof(res.m));
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			for(int k=1; k<=3; k++) {
				res.m[i][j] += (a.m[i][k] % Mod) * (b.m[k][j] % Mod);//矩阵乘法
				res.m[i][j] %= Mod;
			}
		}
	}
	return res;
}
inline void Qmat_pow(int p) {//快速幂
	while (p) {
		if(p & 1) Ans = mul(base, Ans);//让
		base = mul(base, base);
		p >>= 1;
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if(n <= 3) {
			printf("1\n");
			continue;
		}
        int x=n%3;if(!x) x=3;
		init();
		Qmat_pow((n-1)/3);
        /*for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                printf("%lld ", Ans.m[i][j]);
            }
            printf("\n");
        }*/
		printf("%lld\n", Ans.m[x][1]);
	}
}
