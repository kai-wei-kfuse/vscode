#include <iostream>//矩阵快速幂
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int t, n;
struct mat{
	double m[202][202];
}Ans, base;
inline void init() {
	memset(Ans.m, 0, sizeof(Ans.m));
	//for(int i=1; i<=3; i++) 
        Ans.m[1][1] = 1;//初始化初始矩阵
	memset(base.m, 0, sizeof(base.m));
	for(int i=1;i<=t;i++){
        for(int j=1;j<=t;j++){
            scanf("%lf",&base.m[i][j]);
        }
    }
}
inline mat mul(mat a, mat b) {
	mat res;
	memset(res.m, 0, sizeof(res.m));
	for(int i=1; i<=t; i++) {
		for(int j=1; j<=t; j++) {
			for(int k=1; k<=t; k++) {
				res.m[i][j] += a.m[i][k]*b.m[k][j];//矩阵乘法
			}
		}
	}
	return res;
}
inline void fpow(int p) {//快速幂
	while (p) {
		if(p & 1) Ans = mul(Ans, base);//让
		base = mul(base, base);
		p >>= 1;
	}
}

int main() {
	scanf("%d", &t);
	scanf("%d", &n);
		init();
		fpow(n);
        for(int i=1;i<=1;i++){
            for(int j=1;j<=t;j++){
                printf("%.4lf ", Ans.m[i][j]);
            }
            printf("\n");
        }
		//printf("%lld\n", Ans.m[x][1]);
}
